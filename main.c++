#include "headerFiles/Admin.h"

int main() {
  try {
  Client c1, c2, c3, c4;
  Employee e1("Sayed", "12340678920340", "1454lkj'", 5500);

    c1 = Client("khaled", "12340678920340", "1454uigf", 2300);
    c2 = Client("Ahmed", "12340678920340", "1454uigf", 2300);
    c3 = Client("Mohamed", "12340678920340", "1454uigf", 2300);
    e1.addClient(c1);
    e1.addClient(c2);
    e1.addClient(c3);
    c1.displayInfo();
    cout << allClients.size() << endl;

  } catch (Validation::Name n) {
    n.nameError();
  } catch (Validation::ID i) {
    i.idError();
  } catch (Validation::Password p) {
    p.passwordError();
  } catch (Validation::Balance b) {
    b.balanceError();
  } catch (Validation::Salary s) {
    s.salaryError();
  }
  return 0;
}
