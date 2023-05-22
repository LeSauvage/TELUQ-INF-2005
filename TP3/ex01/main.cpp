#include <cstdlib>
#include <iostream>

#include "Contact.hpp"

using std::cout;
using std::endl;

static void makeContact(const string& name, const string& sexe, const int& age,
                        const string& phone) {
  try {
    Contact contact(name, sexe, age, phone);
    cout << contact << endl;
  } catch (const std::invalid_argument& e) {
    cout << e.what() << endl;
  }
}

int main(void) {
  // Valid Contact parameters
  makeContact("John Doe", "M", 42, "418-998-1515");

  makeContact("Jacques Rivard", "M", 40, "555-1212");

  cout << endl;
  // Invalid Contact parameters
  makeContact("Invalid Contact", "M", -10, "555-1212");

  makeContact("Invalid Contact", "" , 42, "555-1212");

  return EXIT_SUCCESS;
}
