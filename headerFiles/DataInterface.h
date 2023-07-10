#include "Admin.h"


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
  // Add Client To File
  void addClient(Client &client) {
    ofstream clientFile("Client.txt", ios::binary);
    if (clientFile.is_open()) {
        clientFile << "Name: " << client.getName() << endl;
        clientFile << "ID: " << client.getID() << endl;
        clientFile << "Password: " << client.getPassword() << endl;
        clientFile << "Balance: " << client.getBalance() << endl;
        clientFile.close();
    }
    else {
        cout << "Failed to open file: clients.txt" << endl;
    }
  }
};