#include "Admin.h"

int main() {
  Client c1, c2;
  try {
    c1 = Client("khaled", "12340678920340", "1454uigf", 2500);
    c2 = Client("Sayed", "12340678920340", "1454lkj'", 2500);
  }
  catch (Validation::Name n) {
    n.nameError();
  }
  catch (Validation::ID i)
  {
    i.idError();
  }
  catch (Validation::Password p)
  {
    p.passwordError();
  }
  catch (Validation::Balance b) {
    b.balanceError();
  }

  c1.transfer(c2, 300);
  c1.displayInfo();
  c2.displayInfo();
  Client::numberOfClients();

  Admin a1, a2, a3;
  try {
    a1 = Admin("Ahmed", "12345683162340", "12345hgd", 5000);
    a2 = Admin("Salah", "12345683162340", "12345hgd", 5000);
    a3 = Admin("Salah", "12345683162340", "12345hgd", 5000);
  }
  catch (Validation::Name n)
  {
    n.nameError();
  }
  catch (Validation::ID i)
  {
    i.idError();
  }
  catch (Validation::Password p)
  {
    p.passwordError();
  }
  catch (Validation::Salary b)
  {
    b.salaryError();
  }
  a1.displayInfo();
  a2.displayInfo();
  Admin::numberOfAdmins();

  Employee e1, e2;
  try {
    e1 = Employee("Ahmed", "12345683162340", "12345hgd", 5000);
    e2 = Employee("Salah", "12345683162340", "12345hgd", 5000);
  }
  catch (Validation::Name n)
  {
    n.nameError();
  }
  catch (Validation::ID i)
  {
    i.idError();
  }
  catch (Validation::Password p)
  {
    p.passwordError();
  }
  catch (Validation::Salary b)
  {
    b.salaryError();
  }
  e1.displayInfo();
  e2.displayInfo();
  Employee::numberOfEmployees();

  return 0;
}