#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

#define RED "\e[0;31m"
#define CRESET "\e[0m"

using std::cout;
using std::endl;
using std::string;

/*
** Si aucun argument n'est passé, le programme affiche un message d'erreur"
*/
static void usage(const string& name) {
  cout << RED "Usage: " << name << " <number>" CRESET << endl;
  exit(EXIT_FAILURE);
}

/*
** Cette fonction permet de valider si une chaîne de caractères est un nombre
** entier entre 1 et 10 inclusivement. Elle retourne le nombre si c'est le cas,
*/
static int validateEntry(const string& entry) {
  int val = std::stoi(entry);
  if (val < 1 || val >= 11) {  // 1 to 10 inclusive
    throw std::invalid_argument("Invalid number");
  }
  return val;
}

/*
** Cette fonction affiche la table de multiplication du nombre passé en
** paramètre.
*/
static void execMultiple(int val) {
  for (int i = 1; i < 11; ++i) {
    cout << val << " x " << i << " = " << val * i << endl;
  }
}

/*
** Le programme prend en paramètre un nombre entier entre 1 et 10 inclusivement.
*/
int main(int ac, char** av) {
  if (ac != 2) usage(av[0]);
  try {
    int val = validateEntry(av[1]);
    execMultiple(val);
  } catch (const std::exception& e) {
    cout << RED << "Error: " << e.what() << CRESET << endl;
  }
  return EXIT_SUCCESS;
}
