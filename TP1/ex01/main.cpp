#include <cstdlib>
#include <iostream>

#include "Convert.hpp"

using std::cout;
using std::endl;

/*
** Si aucun argument n'est passé, le programme affiche un message d'erreur"
*/
static void usage(const std::string& name) {
  cout << RED "Usage: " << name << " [valeur en CAD$]" CRESET << endl;
  exit(EXIT_FAILURE);
}

int main(int ac, char** av) {
  if (ac != 2) usage(av[0]);

  try {
    // Création d'une instance de la classe Convert avec la valeur passée en argument
    Convert val(av[1]);

    // Affichage des conversions
    val.display();
  } catch (std::exception& e) {
    // Catch une exception en cas d'erreur exemple: argument invalide, overflow, etc.
    cout << RED "Error: " << e.what() << CRESET << endl;
  }
  return EXIT_SUCCESS;
}
