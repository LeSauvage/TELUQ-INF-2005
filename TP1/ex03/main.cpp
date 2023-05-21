#include <iostream>

using std::cout;
using std::endl;

#define LIMIT 1000

#ifndef DEBUG
#define DEBUG 1  // 0: Hide 1: Display actual squar
#endif

/*
** Cette fonction affiche un carré de '#' de la taille passée en paramètre.
** Si la macro DEBUG est définie à 0, la fonction ne fait rien.
*/
static void displaySquare(int size) {
  if (!DEBUG) return;
  for (int x = 0; x < size; ++x) {
    for (int y = 0; y < size; ++y) {
      cout << "#";
    }
    cout << endl;
  }
  cout << endl;
}

/*
** Cette fonction affiche les carrés de 1 à 31. Si le carré est plus grand que
** la valeur passée en paramètre, la fonction s'arrête.
** La fonction appelle la fonction displaySquare pour afficher le carré.
*/
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
