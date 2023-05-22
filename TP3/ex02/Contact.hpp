#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <ostream>
#include <string>

using std::string;

class Bus;

class Contact {
 public:
  Contact(const string&, const string&, const int&, const string&);
  virtual ~Contact();

  const string& getName() const;
  const string& getSexe() const;
  const int& getAge() const;
  const string& getPhone() const;

  void setBus(Bus*);
  void display() const;

 private:
  string name_;
  string sexe_;
  int age_;
  string phone_;
  Bus* currentBus_;
};

std::ostream& operator<<(std::ostream&, const Contact&);

#endif  // CONTACT_HPP_
