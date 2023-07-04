#include <iostream>
#include <string>
using namespace std;

class Validation {
public:
  // Name
  static void checkName(string name) {
    if (name.size() < 5 || name.size() > 20) {
      throw Name();
    }
    for (int i = 0; i < name.size(); i++)
    {
      if (!isalpha(name[i]))
      {
        throw Name();
      }
    }
  }
  class Name {
  public:
    void nameError() {
      cout << " Name size must be >= 5 chars and <= 20 chars and must be only alphabetic characters!" << endl;
    }
  };

  // ID
  static void checkID(string id) {
    if (id.size() != 14)
    {
      throw ID();
    }
    for (int i = 0; i < id.size(); i++)
    {
      if (!isdigit(id[i]))
      {
        throw ID();
      }
    }
  }
  class ID {
  public:
    void idError() {
      cout << " ID must be 14 numeric characters!" << endl;
    }
  };

  // Password
  static void checkPassword(string password) {
    if (password.size() < 8 || password.size() > 20)
    {
      throw Password();
    }
    for (int i = 0; i < password.size(); i++)
    {
      if (password[i] == ' ')
      {
        throw Password();
      }
    }
  }
  class Password {
  public:
    void passwordError()
    {
      cout << " Password size must be >= 8 chars and <= 20 chars with no white spaces!" << endl;
    }
  };

  // Balance
  static void checkBalance(double balance) {
    if (balance < 1500)
    {
      throw Balance();
    }
  }
  class Balance {
  public:
    void balanceError()
    {
      cout << " Minimum balance to make account is 1500!" << endl;
    }
  };

  // Salary
  static void checkSalary(double salary) {
    if (salary < 5000)
    {
      throw Salary();
    }
  }
  class Salary {
  public:
    void salaryError()
    {
      cout << " Minimum salary not less than 5000!" << endl;
    }
  };
};