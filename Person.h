#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Person {
  string name;
  string id;

public:
  Person() {
    name = id = "Not Set";
  }
  Person(string name, string id) {
    checkName(name);
    this->name = name;
    checkID(id);
    this->id = id;
  }

  // Setters
  void setName(string name) {
    checkName(name);
    this->name = name;
  }

  // Getters
  string getName() {
    return name;
  }
  string getID()
  {
    return id;
  }
  
  // Methods
  virtual void displayInfo() = 0;
  // virtual string type() = 0;

  // Exception Handiling
  void checkName(string name) {
    if (name.size() < 5 || name.size() > 20) {
      // cout << type();
      throw NameErrors();
    }
    for (int i = 0; i < name.size(); i++)
    {
      if ((name[i] < 65 || name[i] > 122) || (name[i] > 90 && name[i] < 97)) {
        // cout << type();
        throw NameErrors();
      }
    }
  }
  class NameErrors {
  public:
    void nameError() {
      cout << " Name size must be >= 5 chars and <= 20 chars and must be only alphabetic characters!" << endl;
    }
  };
  void checkID(string id){
    if (id.size() != 14) {
      // cout << type();
      throw IDError();
    }
    for (int i = 0; i < id.size(); i++) {
      if (!(id[i] >= 48 && id[i] <= 57)) {
        // cout << type();
        throw IDError();
      }
    }
  }
  class IDError {
  public:
    void idError()
    {
      cout << " ID must be 14 numeric characters!" << endl;
    }
  };
};