#include "Carre.hpp"

#include "Point.hpp"

Carre::Carre(const int& x, const int& y, const int& cote)
    : Point(x, y), cote_(cote) {
  return;
}

Carre::~Carre() { return; }

void Carre::afficher() const {
  cout << "Carre: (" << getX() << ", " << getY() << ") cote: " << cote_ << endl;
}
