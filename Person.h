#include "Validation.h"
#include <fstream>

class Person {
  string name, id, password;
public:
  Person() {
    name = id = password = "Not Set";
  }
  Person(string name, string id, string password) {
    Validation::checkName(name);
    this->name = name;
    Validation::checkID(id);
    this->id = id;
    Validation::checkPassword(password);
    this->password = password;
  }

  // Setters
  void setName(string name) {
    Validation::checkName(name);
    this->name = name;
  }
  void setPassword(string password) {
    Validation::checkPassword(password);
    this->password = password;
  }
  
  // Getters
  string getName() {
    return name;
  }
  string getID()
  {
    return id;
  }
  string getPassword()
  {
    return password;
  }
  
  // Methods
  virtual void displayInfo() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
  };
};