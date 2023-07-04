#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Person {
  string name, id, password;
public:
  Person() {
    name = id = password = "Not Set";
  }
  Person(string name, string id, string password) {
    checkName(name);
    this->name = name;
    checkID(id);
    this->id = id;
    checkPassword(password);
    this->password = password;
  }

  // Setters
  void setName(string name) {
    checkName(name);
    this->name = name;
  }
  void setPassword(string password) {
    checkPassword(password);
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
  
  // Methods
  virtual void displayInfo() {
    cout << " Name: " << name << endl;
    cout << " ID: " << id << endl;
  };

  // Exception Handiling
  void checkName(string name) {
    if (name.size() < 5 || name.size() > 20) {
      throw NameErrors();
    }
    for (int i = 0; i < name.size(); i++) {
      if (!isalpha(name[i])) {
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
      throw IDError();
    }
    for (int i = 0; i < id.size(); i++) {
      if (!isdigit(id[i])) {
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
  void checkPassword(string password)
  {
    if (password.size() < 8 || password.size() > 20)
    {
      throw PasswordErrors();
    }
    for (int i = 0; i < password.size(); i++)
    {
      if (password[i] == ' ')
      {
        throw PasswordErrors();
      }
    }
  }
  class PasswordErrors
  {
  public:
    void passError()
    {
      cout << " Password size must be >= 8 chars and <= 20 chars with no white spaces!" << endl;
    }
  };
};