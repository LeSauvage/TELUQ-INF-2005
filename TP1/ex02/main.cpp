#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
// Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define CRESET "\e[0m"

using std::cout;
using std::endl;
using std::string;

static void usage(const string& name) {
  cout << "Usage: " << name << " <number>" << endl;
  exit(EXIT_FAILURE);
}

static int validateEntry(const string& entry) {
  int val = std::stoi(entry);
  if (val < 1 || val >= 11) {  // 1 to 10 inclusive
    throw std::invalid_argument("Invalid number");
  }
  return val;
}

static void execMultiple(int val) {
  for (int i = 1; i < 11; ++i) {
    cout << val << " x " << i << " = " << val * i << endl;
  }
}

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
