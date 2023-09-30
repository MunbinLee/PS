#include <iostream>

using namespace std;

struct LinkedList {
  struct Node {
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}
  };

  Node *head = nullptr;

  [[nodiscard]] bool isEmpty() const {
    return !head;
  }

  void addFront(int data) {
    Node *pNode = new Node(data);
    if (isEmpty()) head = pNode;
    else {
      pNode->next = head;
      head = pNode;
    }
  }

  void deleteFront() {
    head = head->next;
  }
};

struct Stack : LinkedList {
  void push(int num) {
    addFront(num);
  }

  bool empty() {
    return isEmpty();
  }

  int top() {
    if (empty()) return -1;

    return head->data;
  }

  int pop() {
    if (empty()) return -1;

    int res = top();
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

  Stack st;
  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int num;
      cin >> num;
      st.push(num);
    } else if (cmd == "pop") {
      cout << st.pop() << '\n';
    } else if (cmd == "size") {
      cout << st.size() << '\n';
    } else if (cmd == "empty") {
      cout << st.empty() << '\n';
    } else if (cmd == "top") {
      cout << st.top() << '\n';
    }
  }
  return 0;
}
