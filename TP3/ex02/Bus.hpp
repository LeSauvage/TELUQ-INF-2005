
#ifndef BUS_HPP_
#define BUS_HPP_

#include <map>
#include <string>

#define MAX_PASSENGERS 40

class Contact;

enum BusType { FUMEUR = 1, NONFUMEUR };

class Bus {
 public:
  Bus(const std::string& name_, const int& type_);
  virtual ~Bus();

  std::string getType() const;
  const std::string& getName() const;

  void addPassenger(Contact* contact);
  void removePassenger(Contact* contact);
  void display() const;

 private:
  const std::string name_;
  const int type_;
  int size_;
  std::map<int, Contact*> passengers_;
};

#endif  // BUS_HPP_
