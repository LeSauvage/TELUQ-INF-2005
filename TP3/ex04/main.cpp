#include <cstdlib>

#include "Carre.hpp"
#include "Cube.hpp"
#include "Point.hpp"

int main() {
  Point p1(1, 2);
  p1.afficher();
  cout << endl;

  Carre c1(0, 0, 5);
  c1.afficher();
  cout << endl;

  Carre c2(5, 5, 5);
  c2.afficher();
  cout << endl;

  Cube cube1(c1, c2);
  cube1.afficher();
  return EXIT_SUCCESS;
}
