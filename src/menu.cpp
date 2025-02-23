#include "operation.h"
#include <iostream>

void drawMenu(Operation *op) {
  // Main Menu
  std::cout << "[1] Create Board\n";
  std::cout << "[2] Choose Board\n";
  std::cout << "[3] Edit Board\n";
  std::cout << "[4] Delete Board\n";
  std::cout << "[5] Exit\n";

  std::cout << "Choose Operation: ";
  int oper = 0;
  std::cin >> oper;
  switch (oper) {
  case 1:
    *op = Operation::Create;
    break;
  case 2:
    *op = Operation::Choose;
    break;
  case 3:
    *op = Operation::Edit;
    break;
  case 4:
    *op = Operation::Delete;
    break;
  case 5:
    *op = Operation::Exit;
    break;
  default:
    *op = Operation::None;
    break;
  }
  std::cout << "\n";
}
