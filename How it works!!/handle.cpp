#include <iostream>
#include <windows.h>

int main() {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

  // Change text color to green
  SetConsoleTextAttribute(console, FOREGROUND_GREEN);

  // Print a message with the changed text color
  std::cout << "This is a message in green!" << std::endl;

  // Set the cursor position to row 5, column 10
  COORD cursorPosition;
  cursorPosition.X = 10;
  cursorPosition.Y = 5;
  SetConsoleCursorPosition(console, cursorPosition);

  // Print another message at the new cursor position
  std::cout << "Cursor position: (10, 5)" << std::endl;

  return 0;
}

