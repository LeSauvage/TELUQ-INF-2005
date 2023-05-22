#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

using std::cout;
using std::endl;

class Point {
 public:
  Point(const int& x, const int& y);
  virtual ~Point();

  const int& getX() const;
  const int& getY() const;

  virtual void afficher() const;

 protected:
  int x_;
  int y_;
};

#endif  // POINT_HPP_
