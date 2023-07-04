#include "Admin.h"

int main() {
  Client c1, c2;
  try {
    c1 = Client("khaled", "12340678920340", "1454uigf", 2500);
    c2 = Client("Saye", "12340678920340", "1454lkj'", 2500);
  } catch (Validation::Name n) {
    n.nameError();
  }
  catch (Validation::ID i)
  {
    i.idError();
  }
  catch (Validation::Password p)
  {
    p.passError();
  }
  catch (Validation::Balance b)
  {
    b.balanceError();
  }

  c1.transfer(c2, 300);
  c1.displayInfo();
  c2.displayInfo();

  Client::numberOfClients();

  // Employee e1;
  // try {
  //   e1 = Employee("Ahmed", "12345683162340", "12345hgd", 5000);
  //   e1.displayInfo();
  // } catch(Person::NameErrors n) {
  //   n.nameError();
  // } catch(Person::IDError i) {
  //   i.idError();
  // }
  // catch (Person::PasswordErrors p) {
  //   p.passError();
  // }
  // catch (Employee::SalaryError s) {
  //   s.salary_Error();
  // }

  // Admin a1;
  // try {
  //   a1 = Admin("Sayed", "12345683162340", "12345hfg", 8000);
  //   a1.displayInfo();
  // } catch(Person::NameErrors n) {
  //   n.nameError();
  // } catch(Person::IDError i) {
  //   i.idError();
  // } catch (Person::PasswordErrors p) {
  //   p.passError();
  // } catch (Admin::SalaryError s) {
  //   s.salary_Error();
  // }

  return 0;
}