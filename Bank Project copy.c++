#include "Admin.h"


int main() {
  // Client c1, c2;
  // try {
  //   c1 = Client("khaled", "12340678920340", "1454", 1500);
  // } catch(Person::NameErrors n) {
  //   n.nameError();
  // } catch(Person::IDError i) {
  //   i.idError();
  // } catch(Client::PinCodeErrors p) {
  //   p.pinError();
  // } catch(Client::BalanceError b) {
  //   b.balanceError();
  // }

  Admin a1;
  try {
    a1 = Admin("Salah", "12345683162340", "12345hg", 5000);
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