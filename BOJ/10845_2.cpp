#include <iostream>

using namespace std;

struct LinkedList {
  struct Node {
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}
  };

  Node *head = nullptr;
  Node *tail = nullptr;

  [[nodiscard]] bool isEmpty() const {
    return !head;
  }

  void addBack(int data) {
    Node *pNode = new Node(data);

    if (isEmpty()) {
      head = pNode;
      tail = pNode;
    } else {
      tail->next = pNode;
      tail = pNode;
    }
  }

  void deleteFront() {
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }
  }
};

struct Queue : LinkedList {
  void push(int num) {
    addBack(num);
  }

  bool empty() {
    return isEmpty();
  }

  int front() {
    if (empty()) return -1;

    return head->data;
  }

  int back() {
    if (empty()) return -1;

    return tail->data;
  }

  int pop() {
    if (empty()) return -1;

    int res = front();
    deleteFront();
    return res;
  }

  int size() {
    int cnt = 0;
    Node *pNode = head;
    while (pNode) {
      cnt++;
      pNode = pNode->next;
    }
    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  Queue q;
  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int num;
      cin >> num;
      q.push(num);
    } else if (cmd == "pop") {
      cout << q.pop() << '\n';
    } else if (cmd == "size") {
      cout << q.size() << '\n';
    } else if (cmd == "empty") {
      cout << q.empty() << '\n';
    } else if (cmd == "front") {
      cout << q.front() << '\n';
    } else if (cmd == "back") {
      cout << q.back() << '\n';
    }
  }
  return 0;
}
