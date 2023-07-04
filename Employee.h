#include "Client.h"

class Employee : public Person {
protected:
  Client cl;
  double salary;
  static int counter;

public:
  Employee() {
    salary = 0;
  }
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
  
  class ClientInfo {
  public:
    void displayClientInfo(Client &client) {
      client.displayInfo();
    }
    void editName(Client &client, string name) {
      client.setName(name);
    }
    void deposit(Client &client, double amount) {
      client.deposit(amount);
    }
    void withdraw(Client &client, double amount) {
      client.withdraw(amount);
    }
    void transfer(Client &client, Client &transTo, double amount) {
      client.transfer(transTo, amount);
    }
  };
};

int Employee::counter = 0;