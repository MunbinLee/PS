#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

enum {
  ASSIGN = 1,
  REPEAT = 2,
  STOP = 3,
  PRINT = 4
};

unordered_map<char, int> vars;

int getExpType(const string &exp) {
  if (islower(exp[0])) return ASSIGN;
  if (exp == "REPEAT") return REPEAT;
  if (exp == "STOP") return STOP;
  if (exp == "PRINT") return PRINT;

  return -1;
}

void assign(char var, int value) {
  vars[var] = value;
}

void print(char var) {
  cout << var << " = " << vars[var] << '\n';
}

bool processExp() {
  string exp;
  cin >> exp;
  int expType = getExpType(exp);

  if (expType == ASSIGN) {
    string dummy, value;
    cin >> dummy >> value;
    char var = exp[0];
    int num = stoi(value);

    assign(var, num);
    return true;
  }

  if (expType == PRINT) {
    string value;
    cin >> value;
    char var = value[0];

    print(var);
    return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string dummy;
  cin >> dummy;
  while (processExp());
  return 0;
}
