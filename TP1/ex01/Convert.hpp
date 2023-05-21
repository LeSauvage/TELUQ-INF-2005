#ifndef CONVERT_HPP_
#define CONVERT_HPP_

// Regular text
#define RED "\e[0;31m"
#define YEL "\e[0;33m"
#define CRESET "\e[0m"

#include <string>

class Convert {
 public:
  Convert(const std::string& val);
  void display() const;

  virtual ~Convert();

 private:
  float val_;
  static const float TauxChange_[];
};

#endif  // CONVERT_HPP_
