#include "Client.h"

class Employee : public Person {
  Client cl;
  string password;
  double salary;

public:
  Employee() {
    salary = 0;
  }
  Employee(string name, string id, string password, double salary) : Person(name, id) {
    checkPassword(password);
    this->password = password;
    checkSalary(salary);
    this->salary = salary;
  }

  // Setters
  void setPassword(string password)
  {
    checkPassword(password);
    this->password = password;
  }
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
  virtual string type() { return "Employee"; }
  void displayInfo() {
    cout << type() << " Name: " << getName() << endl;
    cout << type() << " ID: " << getID() << endl;
    cout << type() << " Salary: " << salary << endl;
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
    void editPinCode(Client &client, string pinCode) {
      client.setPinCode(pinCode);
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
  void checkPassword(string password)
  {
    if (password.size() < 8 || password.size() > 20)
    {
      cout << type();
      throw PasswordErrors();
    }
    for (int i = 0; i < password.size(); i++)
    {
      if (password[i] == ' ')
      {
        cout << type();
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
  void checkSalary(double salary)
  {
    if (salary < 5000)
    {
      cout << type();
      throw SalaryError();
    }
  }
  class SalaryError
  {
  public:
    void salary_Error()
    {
      cout << " Minimum salary not less than 5000!" << endl;
    }
  };
};