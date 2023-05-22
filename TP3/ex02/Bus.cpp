
#include "Bus.hpp"

#include <iostream>

#include "Contact.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CRESET "\e[0m"

using std::cout;
using std::endl;

Bus::Bus(const std::string& name, const int& type)
    : name_(name), type_(type), size_(0) {
  return;
}

Bus::~Bus() {
  std::map<int, Contact*>::iterator it;

  for (it = passengers_.begin(); it != passengers_.end(); ++it) {
    it->second->setBus(nullptr);
  }
  return;
}

std::string Bus::getType() const {
  if (type_ == NONFUMEUR)
    return (GRN "NON FUMEUR" CRESET);
  else
    return (RED "FUMEUR" CRESET);
}

const std::string& Bus::getName() const { return name_; }

void Bus::addPassenger(Contact* contact) {
  if (contact == nullptr) throw std::invalid_argument("Invalid Contact");
  if (size_ == MAX_PASSENGERS) throw std::invalid_argument("Bus is full");
  passengers_[this->size_] = contact;
  ++size_;
}

void Bus::removePassenger(Contact* contact) {
  if (contact == nullptr) throw std::invalid_argument("Invalid Contact");
  if (size_ == 0) throw std::invalid_argument("Bus is empty");

  std::map<int, Contact*>::iterator it;

  for (it = passengers_.begin(); it != passengers_.end(); ++it) {
    if (it->second == contact) {
      passengers_.erase(it);
      --size_;
      return;
    }
  }
  throw std::invalid_argument("Contact not found");
}

void Bus::display() const {
  cout << this->getName() << " : " << this->getType() << endl;
  if (this->passengers_.empty()) {
    cout << "No passengers" << endl;
    return;
  }

  std::map<int, Contact*>::const_iterator it;

  for (it = passengers_.begin(); it != passengers_.end(); ++it) {
    cout << "Passenger " << it->first << ":" << it->second->getName() << endl;
  }
}
