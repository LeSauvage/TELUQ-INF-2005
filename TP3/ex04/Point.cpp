
#include "Point.hpp"

Point::Point(const int& x, const int& y) : x_(x), y_(y) { return; }

Point::~Point() { return; }

const int& Point::getX() const { return x_; }

const int& Point::getY() const { return y_; }

void Point::afficher() const {
  cout << "Point: (" << x_ << ", " << y_ << ")" << endl;
  return;
}
