#include "Contact.hpp"

#include <iostream>
#include <ostream>

using std::cout;
using std::endl;

// Constructor
Contact::Contact(const string& name, const string& sexe, const int& age,
                 const string& phone)
    : name_(name), sexe_(sexe), age_(age), phone_(phone) {
  if (name_.empty() || sexe_.empty() || age_ < 0 || phone_.empty())
    throw std::invalid_argument("Invalid Contact parameters");
  return;
}

// Destructor
Contact::~Contact() { return; }

// Getters
const string& Contact::getName() const { return name_; }

const string& Contact::getSexe() const { return sexe_; }

const int& Contact::getAge() const { return age_; }

const string& Contact::getPhone() const { return phone_; }

void Contact::display() const {
  cout << "Name: " << name_ << endl;
  cout << "Sexe: " << sexe_ << endl;
  cout << "Age: " << age_ << endl;
  cout << "Phone: " << phone_ << endl;
}

std::ostream& operator<<(std::ostream& o, const Contact& contact) {
  o << "Name: " << contact.getName() << endl;
  o << "Sexe: " << contact.getSexe() << endl;
  o << "Age: " << contact.getAge() << endl;
  o << "Phone: " << contact.getPhone();
  return o;
}
