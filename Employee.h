#include "Client.h"

class Employee : public Person {
  Client cl;
  double salary;
  static int counter;

public:
  Employee() {
    salary = 0;
  }
  Employee(string name, string id, string password, double salary) : Person(name, id, password) {
    checkSalary(salary);
    this->salary = salary;
  }

  // Setters

  void setSalary(double salary) {
    checkSalary(salary);
    this->salary = salary;
  }

  // Getters
  double getSalary()
  {
    return salary;
  }

  // Methods
  static int numberOfEmployees() {
    return counter;
  }
  void displayInfo() {
    Person::displayInfo();
    cout << " Salary: " << salary << endl;
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
  
  // Exception Handiling
  void checkSalary(double salary) {
    if (salary < 5000)
    {
      throw SalaryError();
    }
  }
  class SalaryError {
  public:
    void salary_Error()
    {
      cout << " Minimum salary not less than 5000!" << endl;
    }
  };
};

int Employee::counter = 0;