#include <cstdlib>
#include <iostream>

#include "Convert.hpp"

using std::cout;
using std::endl;

static void usage(const std::string& name) {
  cout << RED "Usage: " << name << " [valeur en CAD$]" CRESET << endl;
  exit(EXIT_FAILURE);
}

int main(int ac, char** av) {
  if (ac != 2) usage(av[0]);

  try {
    Convert val(av[1]);
    val.display();
  } catch (std::exception& e) {
    cout << RED "Error: " << e.what() << CRESET << endl;
  }
  return EXIT_SUCCESS;
}
