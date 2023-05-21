#include "Convert.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using std::cout;
using std::endl;

const float Convert::TauxChange_[] = {1.35f, 1.4f, 1.6f};

/*
** Cette fonction permet de valider si une chaîne de caractères est un nombre
** à virgule flottante. Elle retourne true si c'est le cas, false sinon.
*/
bool validateFloat(const std::string& str) {
  std::istringstream iss(str);
  float value;
  iss >> value;

  if (iss.fail()) return false;

  return value <= std::numeric_limits<float>::max() &&
         value >= std::numeric_limits<float>::lowest();
}

/*
** Constructeur de la classe Convert. Il prend en paramètre une chaîne de
** caractères qui est la valeur en CAD$ à convertir. Si la chaîne de caractères
** n'est pas un nombre à virgule flottante, une exception de type
** std::invalid_argument est lancée.
*/
Convert::Convert(const std::string& val) {
  if (!validateFloat(val)) {
    throw std::invalid_argument("Invalid argument");
  }
  val_ = std::stof(val);
}

/*
** Destructeur de la classe Convert.
** Il n'y a rien à faire ici car il n'y a pas d'allocation dynamique.
*/
Convert::~Convert() {}

/*
** Cette fonction affiche les conversions de la valeur en CAD$ passée au
** constructeur de la classe Convert.
*/
void Convert::display() const {
  cout << std::fixed << std::setprecision(2);

  cout << YEL "Taux de change pour " << val_ << " CAD$" CRESET << endl;
  for (int i = 0; i < 3; ++i) {
    cout << TauxChange_[i] << " = " << val_ / TauxChange_[i] << " EUR€" << endl;
  }
}
