#include <cstdlib>
#include <iostream>

#include "Bus.hpp"
#include "Contact.hpp"

// Couleurs pour le terminal (facultatif)
#define CYN "\e[0;36m"
#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define RED "\e[0;31m"
#define CRESET "\e[0m"

// Évite la mauvaise pratique de using namespace std;
// Permet de ne pas avoir à écrire std::cout, std::endl, etc.
using std::cout;
using std::endl;

// Prototypes de fonctions, static: ne peut être appelée que dans ce fichier
static Contact* makeContact(const std::string& name, const string& sexe,
                            const int& age, const string& phone) {
  try {
    Contact* tmp = new Contact(name, sexe, age, phone);
    return tmp;
  } catch (const std::invalid_argument& e) {
    cout << e.what() << endl;
  }
  return nullptr;
}

// Assignation d'un bus à un passager
static void assignBus(Contact* passenger, Bus& busNF, Bus& busF) {
  // Si l'utilisateur entre CTRL+D, on évite une boucle infinie
  if (std::cin.eof()) return;

  int userInput;
  // Assignation du bus selon le choix de l'utilisateur
  cout << GRN "Assigning " << passenger->getName() << " to a bus." CRESET
       << endl;
  cout << "– Appuyez sur 1 pour non-fumeurs.\n– Appuyez sur 2 pour fumeurs.\n";
  std::cin >> userInput;

  // Gestion des erreurs
  try {
    if (userInput == FUMEUR) {
      busF.addPassenger(passenger);
      passenger->setBus(&busF);
    } else if (userInput == NONFUMEUR) {
      busNF.addPassenger(passenger);
      passenger->setBus(&busNF);
    } else {
      cout << RED "Invalid input. Please enter 1 or 2 only." CRESET << endl;
      assignBus(passenger, busNF, busF);
    }
  } catch (const std::invalid_argument& e) {
    cout << e.what() << endl;
    // Si l'assignation a échoué, on recommence
    // Appel récursif
    assignBus(passenger, busNF, busF);
    return;
  }
}

int main(void) {
  Bus bus1("Go-GoBus", NONFUMEUR);
  Bus bus2("SleepyRide", FUMEUR);

  // Creation de 4 passagers
  Contact* John = makeContact("John Doe", "M", 42, "418-998-1515");
  Contact* Jacques = makeContact("Jacques Rivard", "M", 40, "555-1212");
  Contact* Jane = makeContact("Jane Doe", "F", 42, "418-998-1515");
  Contact* Jeanne = makeContact("Jeanne Rivard", "F", 40, "555-1212");

  // Assignation des passagers aux bus respectifs selon un choix de l'utilisateur
  assignBus(John, bus1, bus2);
  assignBus(Jacques, bus1, bus2);
  assignBus(Jane, bus1, bus2);
  assignBus(Jeanne, bus1, bus2);

  // Affichage des passagers et des bus
  cout << CYN "\n –– Bus display ––\n" CRESET << endl;
  bus1.display();

  cout << endl;
  bus2.display();

  cout << MAG "\n –– Passenger display ––\n" CRESET << endl;
  John->display();

  cout << endl;
  Jacques->display();

  // Libere la mémoire puisque 'new' a été utilisé
  delete John;
  delete Jacques;
  delete Jane;
  delete Jeanne;

  return EXIT_SUCCESS;
}
