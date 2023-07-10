#include "Client.h"


class Employee : public Person {
protected:
  double salary;
  static int counter;

public:
  // Employee() {
  // }
  Employee(string name, string id, string password, double salary) : Person(name, id, password) {
    Validation::checkSalary(salary);
    this->salary = salary;
    counter++;
  }

  // Setters

  void setSalary(double salary) {
    Validation::checkSalary(salary);
    this->salary = salary;
  }

  // Getters
  double getSalary()
  {
    return salary;
  }

  // Methods
  static void numberOfEmployees() {
    cout << "Number Of Employees: " << counter << endl << endl;
  }
  void displayInfo() {
    Person::displayInfo();
    cout << "Salary: " << salary << endl;
    cout << endl;
  }

  void addClient(Client &client) {
    allClients.push_back(client);
  }
  void editClient(Client &client, string name, string password, double balance) {
    client.setName(name);
    client.setPassword(password);
    client.setBalance(balance);
  }
};
int Employee::counter = 0;