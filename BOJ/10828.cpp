#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

void push(int num) {
  st.emplace(num);
}

int pop() {
  if (st.empty()) return -1;

  int res = st.top();
  st.pop();
  return res;
}

int size() {
  return (int) st.size();
}

int empty() {
  return st.empty();
}

int top() {
  if (st.empty()) return -1;

  return st.top();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int num;
      cin >> num;
      push(num);
    } else if (cmd == "pop") {
      cout << pop() << '\n';
    } else if (cmd == "size") {
      cout << size() << '\n';
    } else if (cmd == "empty") {
      cout << empty() << '\n';
    } else if (cmd == "top") {
      cout << top() << '\n';
    }
  }
  return 0;
}
