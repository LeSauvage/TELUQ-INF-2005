#ifndef CARRE_HPP_
#define CARRE_HPP_

#include "Point.hpp"

// Classe Carre herite de Point
class Carre : public Point {
 public:
  // Constructeur avec deux points (diagonale)
  Carre(const int& x, const int& y, const int& cote);

  virtual ~Carre();

  void afficher() const;

 private:
  int cote_;
};

#endif  // CARRE_HPP_
