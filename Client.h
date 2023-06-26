#include "Person.h"

class Client : public Person {
  string pinCode;
  double balance;

public:
  Client() {
    balance = 0;
  }
  Client(string name, string id, string pin, double b) : Person(name, id) {
    checkPinCode(pin);
    pinCode = pin;
    checkBalance(b);
    balance = b;
  }
  // Setters
  void setPinCode(string pinCode)
  {
    checkPinCode(pinCode);
    this->pinCode = pinCode;
  }

  // Getters
  double getBalance() {
    return balance;
  }

  // Methods
  string type() {return "Client"; }
  double deposit(double amount) {
    balance += amount;
    return balance;
  }
  double withdraw(double amount)
  {
    if (balance < amount)
    {
      cout << "Amount exceeded balance" << endl;
    }
    else
    {
      balance -= amount;
    }
    return balance;
  }
  double transfer(Client &obj, double amount)
  {
    if (balance < amount)
    {
      cout << "Amount exceeded balance" << endl;
    }
    else
    {
      obj.balance += amount;
      balance -= amount;
    }
    return balance;
  }
  void displayInfo() {
    cout << type() << " Name: " << getName() << endl;
    cout << type() << " ID: " << getID() << endl;
    cout << type() << " Balance: " << balance << endl;
    cout << endl;
  }

  // Exception Handiling
  void checkPinCode(string pinCode) {
    if (pinCode.size() != 4) {
      // cout << type();
      throw PinCodeErrors();
    }
    for (int i = 0; i < pinCode.size(); i++) {
      if (!(pinCode[i] >= 48 && pinCode[i] <= 57)) {
        // cout << type();
        throw PinCodeErrors();
      }
    }
  }
  class PinCodeErrors {
  public:
    void pinError() {
      cout <<" Pin Code must be only 4 numeric characters!" << endl;
    }
  };
  void checkBalance(double balance) {
    if (balance < 1500) {
      // cout << type();
      throw BalanceError();
    }
  }
  class BalanceError {
  public:
    void balanceError()
    {
      cout << " Minimum balance to make account is 1500!" << endl;
    }
  };
  
};