#pragma
#include "Employee.h"

class Admin : public Employee {
  static int counter;
public:
  Admin(){}
  Admin(string name, string id, string password, double salary) : Employee(name, id, password, salary) {
    counter++;
    Employee::counter--;
  }
  
  // Methods
  static void numberOfAdmins() {
    cout << "Number Of Admins: " << counter << endl << endl;
  }
  void addEmployee(Employee &employee) {
    // Cases
    allEmployees.push_back(employee);
  }
  Employee* searchEmployee(string id) {
    for(int i = 0; i < allEmployees.size(); i++) {
      if (id == allEmployees[i].getID()) {
        return  &allEmployees[i];
      }
    }
    throw Validation::NotFound();
    return nullptr;
  }
  void listEmployee() {
    if(allEmployees.size() == 0) {
      throw Validation::NotFound();
    }
    for (int i = 0; i < allEmployees.size(); i++) {
      Employee c = allEmployees[i];
      cout << i + 1 << "- ";
      cout << c.getID() << "   ";
      cout << c.getName() << "   ";
      cout << c.getSalary() << endl;
    }
  }
  void editEmployee(string id, string name, string password, double salary) {
    if (searchEmployee(id) == nullptr) {
      throw Validation::NotFound();
    } else {
      searchEmployee(id)->setName(name);
      searchEmployee(id)->setPassword(password);
      searchEmployee(id)->setSalary(salary);
    }
  }
};

int Admin::counter = 0;