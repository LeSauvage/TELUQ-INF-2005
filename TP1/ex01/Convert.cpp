#include "Convert.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using std::cout;
using std::endl;

const float Convert::TauxChange_[] = {1.35f, 1.4f, 1.6f};

bool validateFloat(const std::string& str) {
  std::istringstream iss(str);
  float value;
  iss >> value;

  if (iss.fail()) return false;

  return value <= std::numeric_limits<float>::max() &&
         value >= std::numeric_limits<float>::lowest();
}

Convert::Convert(const std::string& val) {
  if (!validateFloat(val)) {
    throw std::invalid_argument("Invalid argument");
  }
  val_ = std::stof(val);
}

Convert::~Convert() {}

void Convert::display() const {
  cout << std::fixed << std::setprecision(2);

  cout << YEL "Taux de change pour " << val_ << " CAD$" CRESET << endl;
  for (int i = 0; i < 3; ++i) {
    cout << TauxChange_[i] << " = " << val_ / TauxChange_[i] << " EUR€" << endl;
  }
}
