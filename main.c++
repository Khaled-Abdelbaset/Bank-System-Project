#pragma
#include "headerFiles/DataInterface.h"

int main() {
  Client c1, c2, c3, c4;
  Employee e1, e2;
  try {
    e1 = Employee ("Sayed", "12346678920340", "1454lkj'", 5500);
    e2 = Parser::parserToEmployee("Waheed, 12340678928340, 1454uigf, 6300.3");
    c1 = Client("khaled", "12346678520340", "1454uigf", 2300);
    c2 = Client("Ahmed", "22340678928340", "2454uigf", 3300);
    c3 = Client("Mohamed", "32340678920940", "3454uigf", 4300);

    FileManager().removeAllClients();
    e1.addClient(c1);
    e1.addClient(c2);
    e1.addClient(c3);

    FileManager().addClient(c1);
    FileManager().addClient(c2);
    FileManager().addClient(c3);

    vector<Client> clients = FileManager().getAllClients();
    cout << clients.size() << endl;
    for (int i = 0; i < clients.size(); i++) {
      cout << clients[i].getName() << endl;
      cout << clients[i].getID() << endl;
      cout << clients[i].getPassword() << endl;
      cout << clients[i].getBalance() << endl;
    }
    Client::numberOfClients();


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
  } catch (Validation::NotFound n) {
    n.notFound();
  }
  return 0;
}
