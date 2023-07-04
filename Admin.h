#include "Employee.h"

class Admin : public Employee {
  static int counter;
public:
  Admin() {}
  Admin(string name, string id, string password, double salary) : Employee(name, id, password, salary) {}
  // Methods
  static int numberOfEmployees() {
    return counter;
  }
  class EmployeeInfo {
  public:
    void displayEmployeeInfo(Employee &e){
      e.displayInfo();
    }
    void editName(Employee &e, string name) {
      e.setName(name);
    }
    void editPassword(Employee &e, string password) {
      e.setPassword(password);
    }
    void editSalary(Employee &e, double salary) {
      e.setSalary(salary);
    }
  };
};

int Admin::counter = 0;