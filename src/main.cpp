#include "menu.cpp"
#include "operation.h"
#include "title.cpp"
#include <cstdlib>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

class Board {
public:
  std::vector<std::string> todos;
  std::string name;
  Board(std::string name) { this->name = name; }
  void addTodo(std::string todo) { todos.push_back(todo); }
};

int main(int argc, char **argv) {
  Operation op = Operation::None;
  std::vector<Board> boards;

  while (1) {
    int board = 0;
    drawTitle();
    drawMenu(&op);

    switch (op) {
    case Operation::Create: {
      std::string name;
      std::cout << "Enter Board Name: ";
      std::cin >> name;
      boards.push_back(Board(name));
      break;
    }
    case Operation::Choose: {
      if (boards.empty()) {
        std::cout << "No boards available.\n";
        break;
      }
      for (int i = 0; i < boards.size(); i++) {
        std::cout << "[" << i << "]" << " " << boards[i].name << std::endl;
      }
      std::cout << "Choose:";
      std::cin >> board;
      while (1) {
        int oper;
        std::cout << "Todos\n";
        for (int i = 0; i < boards[board].todos.size(); i++) {
          std::cout << "| " << boards[board].todos[i] << std::endl;
        }
        std::cout << "[1] Add Todo\n";
        std::cout << "[2] Exit\n";
        std::cout << "Choose Operation: ";
        std::cin >> oper;
        switch (oper) {
        case 1: {
          std::string todo;
          std::cout << "Enter Todo: ";
          std::cin >> todo;
          boards[board].addTodo(todo);
          break;
        }
        case 2:
          goto ETL;
          break;
        }
      }
    ETL:
      break;
    }
    case Operation::Delete:
      exit(1);
      break;
    case Operation::Exit:
      goto EL;
      break;
    case Operation::None:
      break;
    }
  }
EL:
  return 0;
}
