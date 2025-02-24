#include "board.cpp"
#include "menu.cpp"
#include "operation.h"
#include "title.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  Operation op = Operation::None;
  std::vector<Board> boards;

  while (1) {
    int board = 0;
    drawTitle();
    drawMenu(&op);

    switch (op) {
    case Operation::Create: {
      createBoard(&boards);
      break;
    }
    case Operation::Choose: {
      int e = chooseBoard(&boards, &board);
      if (e < 0) {
        break;
      }
      while (1) {
        int oper;
        printTodos(boards, board);
        std::cout << "[1] Add Todo\n";
        std::cout << "[2] Complete Todo\n";
        std::cout << "[3] Edit Todo\n";
        std::cout << "[4] Delete Todo\n";
        std::cout << "[5] Exit\n";
        std::cout << "Choose Operation: ";
        std::cin >> oper;
        switch (oper) {
        case 1: {
          std::string todo;
          std::cout << "Enter Todo: ";
          std::cin >> todo;
          boards[board].addTodo(Todo(todo));
          break;
        }
        case 2: {
          int todo;
          std::cout << "Enter Todo: ";
          std::cin >> todo;
          boards[board].todos[todo].complete();
          break;
        }
        case 3: {
          int todo;
          std::string td;
          std::cout << "Enter Todo: ";
          std::cin >> todo;
          std::cout << "Enter New Todo: ";
          std::cin >> td;
          boards[board].todos[todo].edit(td);
          break;
        }
        case 4: {
          int todo;
          std::cout << "Enter Todo: ";
          std::cin >> todo;
          boards[board].deleteTodo(todo);
          break;
        }
        case 5:
          goto ETL;
          break;
        }
      }
    ETL:
      board = 0;
      break;
    }
    case Operation::Edit: {
      int e = chooseBoard(&boards, &board);
      if (e < 0) {
        break;
      }
      std::string bd;
      std::cout << "Enter New Board: ";
      std::cin >> bd;
      boards[board].edit(bd);
      board = 0;
      break;
    }
    case Operation::Delete: {
      int e = chooseBoard(&boards, &board);
      if (e < 0) {
        break;
      }
      deleteBoard(&boards, board);
      board = 0;
      break;
    }
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
