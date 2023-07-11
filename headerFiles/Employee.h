#pragma
#include "Client.h"

class Employee : public Person {
protected:
  double salary;
  static int counter;
public:
  
  Employee() {
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
  
  void addClient(Client &client) {
    allClients.push_back(client);
  }
  
  Client* searchClient(string id) {
    for(int i = 0; i < allClients.size(); i++) {
      if (id == allClients[i].getID()) {
        return  &allClients[i];
      }
    }
    throw Validation::NotFound();
    return nullptr;
  }
  
  void listClient() {
    if(allClients.size() == 0) {
      throw Validation::NotFound();
    }
    for (int i = 0; i < allClients.size(); i++) {
      Client c = allClients[i];
      cout << i + 1 << "- ";
      cout << c.getID() << "   ";
      cout << c.getName() << "   ";
      cout << c.getBalance() << endl; 
    }
  }
  
  void editClient(string id, string name, string password, double balance) {
    if (searchClient(id) == nullptr) {
      throw Validation::NotFound();
    } else {
      searchClient(id)->setName(name);
      searchClient(id)->setPassword(password);
      searchClient(id)->setBalance(balance);
    }
  }
};

static vector<Employee> allEmployees;
int Employee::counter = 0;