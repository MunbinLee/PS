#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

void push_front(int num) {
  dq.emplace_front(num);
}

void push_back(int num) {
  dq.emplace_back(num);
}

bool empty() {
  return dq.empty();
}

int pop_front() {
  if (empty()) return -1;

  int res = dq.front();
  dq.pop_front();
  return res;
}

int pop_back() {
  if (empty()) return -1;

  int res = dq.back();
  dq.pop_back();
  return res;
}

int size() {
  return (int) dq.size();
}

int front() {
  if (empty()) return -1;

  return dq.front();
}

int back() {
  if (empty()) return -1;

  return dq.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push_front") {
      int num;
      cin >> num;
      push_front(num);
    } else if (cmd == "push_back") {
      int num;
      cin >> num;
      push_back(num);
    } else if (cmd == "pop_front") {
      cout << pop_front() << '\n';
    } else if (cmd == "pop_back") {
      cout << pop_back() << '\n';
    } else if (cmd == "size") {
      cout << size() << '\n';
    } else if (cmd == "empty") {
      cout << empty() << '\n';
    } else if (cmd == "front") {
      cout << front() << '\n';
    } else if (cmd == "back") {
      cout << back() << '\n';
    }
  }
  return 0;
}
