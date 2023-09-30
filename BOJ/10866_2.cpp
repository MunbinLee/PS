#include <iostream>

using namespace std;

struct LinkedList {
  struct Node {
    int data;
    Node *next;
    Node *prev;

    explicit Node(int data) : data(data), next(nullptr), prev(nullptr) {}
  };

  Node *head = nullptr;
  Node *tail = nullptr;

  [[nodiscard]] bool isEmpty() const {
    return !head;
  }

  void addFront(int data) {
    Node *pNode = new Node(data);

    if (isEmpty()) {
      head = pNode;
      tail = pNode;
    } else {
      pNode->next = head;
      head->prev = pNode;
      head = pNode;
    }
  }

  void addBack(int data) {
    Node *pNode = new Node(data);

    if (isEmpty()) {
      head = pNode;
      tail = pNode;
    } else {
      pNode->prev = tail;
      tail->next = pNode;
      tail = pNode;
    }
  }

  void deleteFront() {
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
    } else {
      head->next->prev = nullptr;
      head = head->next;
    }
  }

  void deleteBack() {
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail->prev->next = nullptr;
      tail = tail->prev;
    }
  }
};

struct Deque : LinkedList {
  void push_front(int num) {
    addFront(num);
  }

  void push_back(int num) {
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

  int pop_front() {
    if (empty()) return -1;

    int res = front();
    deleteFront();
    return res;
  }

  int pop_back() {
    if (empty()) return -1;

    int res = back();
    deleteBack();
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

  Deque dq;
  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push_front") {
      int num;
      cin >> num;
      dq.push_front(num);
    } else if (cmd == "push_back") {
      int num;
      cin >> num;
      dq.push_back(num);
    } else if (cmd == "pop_front") {
      cout << dq.pop_front() << '\n';
    } else if (cmd == "pop_back") {
      cout << dq.pop_back() << '\n';
    } else if (cmd == "size") {
      cout << dq.size() << '\n';
    } else if (cmd == "empty") {
      cout << dq.empty() << '\n';
    } else if (cmd == "front") {
      cout << dq.front() << '\n';
    } else if (cmd == "back") {
      cout << dq.back() << '\n';
    }
  }
  return 0;
}
