#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void push(int num) {
  q.emplace(num);
}

bool empty() {
  return q.empty();
}

int pop() {
  if (empty()) return -1;

  int res = q.front();
  q.pop();
  return res;
}

int size() {
  return (int) q.size();
}

int front() {
  if (empty()) return -1;

  return q.front();
}

int back() {
  if (empty()) return -1;

  return q.back();
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
    } else if (cmd == "front") {
      cout << front() << '\n';
    } else if (cmd == "back") {
      cout << back() << '\n';
    }
  }
  return 0;
}