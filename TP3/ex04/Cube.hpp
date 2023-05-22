
#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "Carre.hpp"

// Classe Cube composée de deux objets de type Carre
class Cube {
 public:
  Cube(const Carre& face_bot, const Carre& face_top);
  virtual ~Cube();

  void afficher() const;

 private:
  Carre face_bot_;
  Carre face_top_;
};

#endif  // CUBE_HPP_
