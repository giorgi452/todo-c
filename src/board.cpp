#include <bits/stdc++.h>
#include <iostream>
#include <vector>

class Todo {
public:
  std::string name;
  bool completed = false;
  Todo(std::string name) { this->name = name; }
  void complete() { this->completed = !this->completed; }
  void edit(std::string newName) { this->name = newName; }
};

class Board {
public:
  std::vector<Todo> todos;
  std::string name;
  Board(std::string name) { this->name = name; }
  void addTodo(Todo todo) { todos.push_back(todo); }
  void deleteTodo(int todo) { todos.erase(todos.begin() + todo); }
  void edit(std::string newName) { this->name = newName; }
};

void createBoard(std::vector<Board> *boards) {
  std::string name;
  std::cout << "Enter Board Name: ";
  std::cin >> name;
  (*boards).push_back(Board(name));
}

void deleteBoard(std::vector<Board> *boards, int board) {
  (*boards).erase((*boards).begin() + board);
}

int chooseBoard(std::vector<Board> *boards, int *board) {
  if ((*boards).empty()) {
    std::cout << "No boards available.\n";
    return -1;
  }
  for (int i = 0; i < (*boards).size(); i++) {
    std::cout << "[" << i << "]" << " " << (*boards)[i].name << std::endl;
  }
  std::cout << "Choose:";
  std::cin >> *board;
  return 0;
}

void printTodos(std::vector<Board> boards, int board) {
  std::cout << "Todos\n";
  for (int i = 0; i < boards[board].todos.size(); i++) {
    std::cout << "[" << i << "] " << boards[board].todos[i].name;
    if (boards[board].todos[i].completed) {
      std::cout << " *";
    }
    std::cout << "\n\n";
  }
}
