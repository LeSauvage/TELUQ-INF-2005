#include <iostream>

using std::cout;
using std::endl;

#define LIMIT 1000

static void displaySquare(int size) {
  for (int x = 0; x < size; ++x) {
    for (int y = 0; y < size; ++y) {
      cout << "#";
    }
    cout << endl;
  }
  cout << endl;
}

static void printSquared(int range) {
  int square;
  for (int i = 1; i < 32; ++i) {  // 32 * 32 = 1024
    square = i * i;
    if (square <= range) {
      cout << "carrés " << i << ":" << i << endl;
      displaySquare(i);
    }
  }
}

int main(void) {
  printSquared(LIMIT);
  return EXIT_SUCCESS;
}
