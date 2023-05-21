#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define CYN "\e[0;36m"
#define CRESET "\e[0m"

using std::cout;
using std::endl;
using std::setw;

/*
** Rempli un tableau à deux dimensions avec des nombres aléatoires
** entre 0 et 100
*/
template <typename T, size_t rows, size_t cols>
void fillArrRandom(T (&arr)[rows][cols]) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      arr[i][j] = rand() % 100;
    }
  }
}

// Affiche un tableau à deux dimensions
template <typename T, size_t rows, size_t cols>
void printArray(T (&arr)[rows][cols]) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      cout << setw(3) << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// Additionne deux tableaux à deux dimensions
template <typename T, size_t rows, size_t cols>
size_t getSum(T (&arr)[rows][cols], T (&arr2)[rows][cols]) {
  size_t sum = 0;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      sum += arr[i][j] + arr2[i][j];
    }
  }
  return sum;
}

int main(void) {
  // Initialisation du générateur de nombres aléatoires afin d'avoir des
  // nombres différents à chaque exécution
  srand(time(NULL));

  // Déclaration des tableaux
  int arr[10][10];
  int arr2[10][10];

  // Remplissage des tableaux
  fillArrRandom(arr);
  fillArrRandom(arr2);

  // Affichage des tableaux
  cout << YEL "Tableau 1:" CRESET << endl;
  printArray(arr);
  cout << YEL "Tableau 2:" CRESET << endl;
  printArray(arr2);

  // Addition des tableaux
  size_t sum = getSum(arr, arr2);
  cout << GRN "Somme des deux tableaux: " CYN << sum << CRESET << endl;
  return EXIT_SUCCESS;
}
