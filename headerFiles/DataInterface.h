#pragma
#include "Parser.h"

class DataSourceInterface {
public:
  // Add
  virtual void addClient(Client) = 0;
  virtual void addEmployee(Employee) = 0;
  virtual void addAdmin(Admin) = 0;
  
  // Get
  virtual vector<Client> getAllClients() = 0;
  virtual vector<Employee> getAllEmployees() = 0;
  virtual vector<Admin> getAllAdmins() = 0;
  
  // Remove
  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};

class FileManager : public DataSourceInterface {
public:
  // Add To File
  void addClient(Client c) {
    ofstream cFile("Client.txt", ios::app);
    if (cFile.is_open()) {
        cFile << c.getName() << endl;
        cFile << c.getID() << endl;
        cFile << c.getPassword() << endl;
        cFile << c.getBalance() << endl;
        cFile.close();
        cout << "Client '" << c.getID() << "' has been added successfully" << endl;
    } else {
      Validation::failedOpenClient();
    }
  }
  void addEmployee(Employee e) {
    ofstream eFile("Employee.txt", ios::app);
    if (eFile.is_open()) {
      eFile << e.getName() << endl;
      eFile << e.getID() << endl;
      eFile << e.getPassword() << endl;
      eFile << e.getSalary() << endl;
      eFile.close();
      cout << "Employee '" << e.getID() << "' has been added successfully" << endl;
    } else {
      Validation::failedOpenEmployee();
    }
  }
  void addAdmin(Admin a) {
    ofstream aFile("Admin.txt", ios::app);
    if (aFile.is_open()) {
        aFile << a.getName() << endl;
        aFile << a.getID() << endl;
        aFile << a.getPassword() << endl;
        aFile << a.getSalary() << endl;
        aFile.close();
        cout << "Admin '" << a.getID() << "' has been added successfully" << endl;
    } else {
      Validation::failedOpenAdmin();;
    }
  }
  
  // Get All
  vector<Client> getAllClients() {
    vector<Client> clients;
    ifstream cFile("Client.txt", ios::in);
    if (cFile.is_open()) {
      string line, name, id, password, balance;
      while (getline(cFile, name) && getline(cFile, id) && getline(cFile, password) && getline(cFile, balance)) {
        Client c;
        c.setName(name), c.setID(id), c.setPassword(password), c.setBalance(stod(balance));
        clients.push_back(c);
      } 
      cFile.close();
      cout << "All clients have been get successfully" << endl;
    } else {
      Validation::failedOpenClient();
    }
    return clients;
  }
  vector<Employee> getAllEmployees() {
    vector<Employee> employees;
    ifstream eFile("Employee.txt", ios::in);
    if (eFile.is_open()) {
      string line, name, id, password, salary;
      while (getline(eFile, name) && getline(eFile, id) && getline(eFile, password) && getline(eFile, salary)) {
        Employee e;
        e.setName(name), e.setID(id), e.setPassword(password), e.setSalary(stod(salary));
        employees.push_back(e);
      } 
      eFile.close();
      cout << "All employees have been get successfully" << endl;
    } else {
      Validation::failedOpenEmployee();
    }
    return employees;
  }
  vector<Admin> getAllAdmins() {
    vector<Admin> admins;
    ifstream aFile("Admin.txt", ios::in);
    if (aFile.is_open()) {
      string line, name, id, password, salary;
      while (getline(aFile, name) && getline(aFile, id) && getline(aFile, password) && getline(aFile, salary)) {
        Admin a;
        a.setName(name), a.setID(id), a.setPassword(password), a.setSalary(stod(salary));
        admins.push_back(a);
      } 
      aFile.close();
      cout << "All admins have been get successfully" << endl;
    } else {
      Validation::failedOpenAdmin();;
    }
    return admins;
  }

  // Remove All
  void removeAllClients() {
    ofstream file("Client.txt", ios::trunc);
    if (file.is_open()) {
      cout << "All clients have been removed successfully" << endl;
      file.close();
    } else {
      Validation::failedOpenClient();
    }
  }
  void removeAllEmployees() {
    ofstream file("Employee.txt", ios::trunc);
    if (file.is_open()) {
      cout << "All employees have been removed successfully" << endl;
      file.close();
    } else {
      Validation::failedOpenEmployee();
    }
  }
  void removeAllAdmins() {
    ofstream file("Admin.txt", ios::trunc);
    if (file.is_open()) {
      cout << "All admins have been removed successfully" << endl;
      file.close();
    } else {
      Validation::failedOpenAdmin();;
    }
  };

  // Add All
  /* static void addAllCtslien(vector<Client> client) {
    ofstream cFile("Client.txt", ios::out);
    if (cFile.is_open()) {
      cFile << "All clients Data: "<< endl;
      for (int i = 0; i < client.size(); i++) {
        cFile << "-Name: " << client[i].getName() << endl;
        cFile << " ID: " << client[i].getID() << endl;
        cFile << " Password: " << client[i].getPassword() << endl;
        cFile << " Balance: " << client[i].getBalance() << endl;
      }
      cFile.close();
      cout << "All clients have been added successfully" << endl;
    }
    else {
      cout << "Failed to open file: Clients.txt" << endl;
    }
  }*/
};
