#pragma
#include "Admin.h"

class Parser {
public:
  static vector<string> split(string line) {
    vector<string> data;
    int st = 0;
    int sep = line.find(',', st);
    while(sep < line.size()) {
      string item = line.substr(st, sep - st);
      if (item[0] == ' ') {
        item.erase(0, 1);
      }
      data.push_back(item);
      st = sep + 1;
      sep = line.find(',', st);
    }
    data.push_back(line.substr(st));
    return data;
  }

  static Client parserToClient(string line) {
    vector<string> data = split(line);
    Client c;
    c.setName(data[0]);
    c.setID(data[1]);
    c.setPassword(data[2]);
    c.setBalance(stod(data[3]));
    return c;
  }
  static Employee parserToEmployee(string line) {
    vector<string> data = split(line);
    Employee e;
    e.setName(data[0]);
    e.setID(data[1]);
    e.setPassword(data[2]);
    e.setSalary(stod(data[3]));
    return e;
  }
  static Admin parserToAdmin(string line) {
    vector<string> data = split(line);
    Admin a;
    a.setName(data[0]);
    a.setID(data[1]);
    a.setPassword(data[2]);
    a.setSalary(stod(data[3]));
    return a;
  }
};