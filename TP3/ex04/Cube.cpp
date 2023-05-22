#include "Cube.hpp"

Cube::Cube(const Carre& face_bot, const Carre& face_top)
    : face_bot_(face_bot), face_top_(face_top) {
  return;
}

Cube::~Cube() { return; }

void Cube::afficher() const {
  cout << "Cube: " << endl;
  face_bot_.afficher();
  face_top_.afficher();
  return;
}
