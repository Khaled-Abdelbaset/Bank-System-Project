#include "Person.h"

class Client : public Person {
  double balance;
  static int counter;
public:
  Client() {
    balance = 0;
  }
  Client(string name, string id, string password, double b) : Person(name, id, password)
  {
    Validation::checkBalance(b);
    balance = b;
    counter++;
  }

  // Getters
  double getBalance() {
    return balance;
  }

  // Methods
  static void numberOfClients() {
    cout << "Number Of Clients: " << counter << endl;
  }
  double deposit(double amount) {
    balance += amount;
    return balance;
  }
  double withdraw(double amount) {
    if (balance < amount) {
      cout << "Amount exceeded balance" << endl;
    }
    else {
      balance -= amount;
    }
    return balance;
  }
  void transfer(Client &obj, double amount) {
    withdraw(amount);
    obj.deposit(amount);
  }
  void displayInfo() {
    Person::displayInfo();
    cout << " Balance: " << balance << endl;
    cout << endl;
  }

  // Exception Handiling


  
};

int Client::counter = 0;