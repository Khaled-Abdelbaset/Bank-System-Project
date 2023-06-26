#include "Admin.h"


int main() {
  Client c1, c2;
  try {
    c1 = Client("khaled", "12340678920340", "1454", 2500);
    c1.displayInfo();
  } catch(Person::NameErrors n) {
    n.nameError();
  } catch(Person::IDError i) {
    i.idError();
  } catch(Client::PinCodeErrors p) {
    p.pinError();
  } catch(Client::BalanceError b) {
    b.balanceError();
  }

  try {
    c2 = Client("Omar", "12340678920340", "1454", 2500);
    c2.displayInfo();
  } catch(Person::NameErrors n) {
    n.nameError();
  } catch(Person::IDError i) {
    i.idError();
  } catch(Client::PinCodeErrors p) {
    p.pinError();
  } catch(Client::BalanceError b) {
    b.balanceError();
  }

  Employee e1;
  try {
    e1 = Employee("Ahmed", "12345683162340", "12345hgd", 5000);
    e1.displayInfo();
  } catch(Person::NameErrors n) {
    n.nameError();
  } catch(Person::IDError i) {
    i.idError();
  }
  catch (Employee::PasswordErrors p) {
    p.passError();
  }
  catch (Employee::SalaryError s) {
    s.salary_Error();
  }

  Admin a1;
  try {
    a1 = Admin("Sayed", "12345683162340", "12345hfg", 8000);
    a1.displayInfo();
  } catch(Person::NameErrors n) {
    n.nameError();
  } catch(Person::IDError i) {
    i.idError();
  } catch (Admin::PasswordErrors p) {
    p.passError();
  } catch (Admin::SalaryError s) {
    s.salary_Error();
  }

  return 0;
}