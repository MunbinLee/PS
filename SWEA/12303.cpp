#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NODE 10000

enum {
  ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99
};

struct Node {
  int data;
  Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;

Node *getNode(int data) {
  node[nodeCnt].data = data;
  node[nodeCnt].next = nullptr;
  return &node[nodeCnt++];
}

void init() {
  head = nullptr;
  nodeCnt = 0;
}

void addNode2Head(int data) { // 1 data
  Node *newNode = getNode(data);
  newNode->next = head;
  head = newNode;
}

void addNode2Tail(int data) { // 2 data
  Node *newNode = getNode(data);
  if (head == nullptr) head = newNode;
  else {
    Node *nodePtr = head;
    while (nodePtr->next) nodePtr = nodePtr->next;
    nodePtr->next = newNode;
  }
}

void addNode2Num(int data, int num) { // 3 data pos
  if (num == 1) {
    addNode2Head(data);
  } else {
    Node *newNode = getNode(data);
    Node *nodePtr = head;
    for (int i = 0; i < num - 2; i++) nodePtr = nodePtr->next;
    newNode->next = nodePtr->next;
    nodePtr->next = newNode;
  }
}

void removeNode(int data) { // 4 data
  if (head->data == data) {
    head = head->next;
    return;
  }

  Node *nodePtr = head;
  while (true) {
    if (nodePtr->next == nullptr) return;
    if (nodePtr->next->data == data) break;
    nodePtr = nodePtr->next;
  }
  nodePtr->next = nodePtr->next->next;
}

int getList(int output[MAX_NODE]) {
  Node *nodePtr = head;
  int i = 0;
  while (nodePtr) {
    output[i++] = nodePtr->data;
    nodePtr = nodePtr->next;
  }
  return i;
}

static void run() {
  while (1) {
    int cmd, data, num, cnt, i;
    int output[MAX_NODE] = {0};

    scanf("%d", &cmd);
    switch (cmd) {
      case ADD_HEAD: // 1
        scanf("%d", &data);
        addNode2Head(data);
        break;
      case ADD_TAIL: // 2
        scanf("%d", &data);
        addNode2Tail(data);
        break;
      case ADD_NUM: // 3
        scanf("%d %d", &data, &num);
        addNode2Num(data, num);
        break;
      case REMOVE: // 4
        scanf("%d", &data);
        removeNode(data);
        break;
      case PRINT: // 5
        cnt = getList(output);
        i = 0;
        while (cnt--)
          printf("%d ", output[i++]);
        printf("\n");
        break;
      case END: // 99
        return;
    }
  }
}

int main(void) {
  //setbuf(stdout, NULL);
  //freopen("sll_input.txt", "r", stdin);

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("#%d\n", t);
    init();
    run();
    printf("\n");
  }

  return 0;
}