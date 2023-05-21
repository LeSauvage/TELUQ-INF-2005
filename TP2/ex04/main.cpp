#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

#define YEL "\e[0;33m"
#define CRESET "\e[0m"

int main(void) {
  // Initialisation du générateur de nombres aléatoires
  srand(time(NULL));

  std::vector<double> vals(20);

  // Initialisation des valeurs random entre 0 et 100
  cout << YEL "Valeurs initiales : " CRESET << endl;
  for (int i = 0; i < 20; i++) {
    vals[i] = rand() % 100;
    cout << vals[i] << endl;
  }

  std::vector<double> exponentielles(20);

  // Calcul des valeurs exponentielles
  cout << YEL "Valeurs exponentielles : " CRESET << endl;
  for (int i = 0; i < 20; i++) {
    exponentielles[i] = exp(vals[i]);
    cout << exponentielles[i] << endl;
  }

  // Tri des valeurs exponentielles
  std::sort(exponentielles.begin(), exponentielles.end());

  // Affichage des valeurs exponentielles triées
  cout << YEL "Valeurs exponentielles triées : " CRESET << endl;
  for (int i = 0; i < 20; i++) {
    cout << exponentielles[i] << endl;
  }
  return EXIT_SUCCESS;
}
