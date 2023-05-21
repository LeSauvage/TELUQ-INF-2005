#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define CYN "\e[0;36m"
#define CRESET "\e[0m"

using std::cout;
using std::endl;

/*
** Rempli un tableau à deux dimensions avec des nombres aléatoires
** entre 0 et 100
*/
template <typename T, int cols>
void fillArrRandom(T (&arr)[cols]) {
  for (int i = 0; i < cols; i++) {
    arr[i] = rand() % 100;
  }
}

template <typename T, int cols>
void printArray(T (&arr)[cols]) {
  for (int i = 0; i < cols; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

template <typename T, int cols>
void RevPrintArray(T (&arr)[cols]) {
  for (int i = cols - 1; i >= 0 ; --i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(void) {
  // Initialisation du générateur de nombres aléatoires afin d'avoir des
  // nombres différents à chaque exécution
  srand(time(NULL));

  // Déclaration du tableau
  int arr[200];

  // Remplissage du tableau
  fillArrRandom(arr);

  // Affichage du tableau
  cout << YEL "Avant triage" CRESET << endl;
  printArray(arr);

  cout << YEL "Apres triage / Croissant" CRESET << endl;
  std::sort(arr, arr + 200);
  printArray(arr);

  cout << YEL "Tableau decroissant" CRESET << endl;
  RevPrintArray(arr);
  return EXIT_SUCCESS;
}
