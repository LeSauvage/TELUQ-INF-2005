#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::string;

static void invalidNeedle(const string& needle) {
  cout << "La lettre " << needle << " n'est pas valide" << endl;
  exit(EXIT_FAILURE);
}

static void invalidHaystack(const string& haystack) {
  cout << "Le mot " << haystack << " n'est pas valide" << endl;
  exit(EXIT_FAILURE);
}

static void displayResults(const std::deque<int>& positions, const string& needle) {
  if (positions.empty()) {
    cout << "La lettre n'a pas été trouvée" << endl;
    return;
  }

  cout << "La lettre '"<< needle <<  "' apparaît aux positions suivantes : ";
  std::deque<int>::const_iterator it;
  // Affiche les positions de la lettre dans le mot
  for (it = positions.begin(); it != positions.end(); ++it) {
    // Formate l'affichage
    if (it + 2 == positions.end())
      cout << *it << " et ";
    else if (it + 1 == positions.end())
      cout << *it;
    else
      cout << *it << ", ";
  }
  cout << endl;
}

static void find(const string& haystack, const string& needle) {
  // Vérifie que le mot et la lettre sont valides
  if (haystack.size() < 10) invalidHaystack(haystack);
  if (needle.size() != 1) invalidNeedle(needle);

  std::deque<int> positions;
  std::size_t pos = 0;
  // Recherche la lettre dans le mot
  // Si la lettre est trouvée, on ajoute sa position dans le conteneur
  while ((pos = haystack.find(needle, pos + 1)) != string::npos) {
    positions.push_back(pos + 1);
  }
  // Affiche les résultats
  displayResults(positions, needle);
}

int main(void) {
  string haystack;
  string needle;

  // Demande à l'utilisateur de saisir un mot de plus de 10 caractères
  cout << "Entrer un mot de plus de 10 caractères: ";
  getline(std::cin, haystack);

  // Demande à l'utilisateur de saisir une lettre
  cout << "Lettre à rechercher : ";
  getline(std::cin, needle);

  // Recherche la lettre dans le mot
  find(haystack, needle);
  return EXIT_SUCCESS;
}
