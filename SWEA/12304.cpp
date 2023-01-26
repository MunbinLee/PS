#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NODE 10000

enum {
  ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99
};

struct Node {
  int data;
  Node *prev;
  Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;
Node *tail;

Node *getNode(int data) {
  node[nodeCnt].data = data;
  node[nodeCnt].prev = nullptr;
  node[nodeCnt].next = nullptr;
  return &node[nodeCnt++];
}

void init() {
  if (head) {
    head = nullptr;
    tail = nullptr;
    nodeCnt = 0;
  }
}

void addNode2Head(int data) { // 1 data
  Node *newNode = getNode(data);
  if (!head) tail = newNode;
  else {
    newNode->next = head;
    head->prev = newNode;
  }
  head = newNode;
}

void addNode2Tail(int data) { // 2 data
  if (!head) {
    addNode2Head(data);
    return;
  }

  Node *nodePtr = head;
  while (nodePtr->next) nodePtr = nodePtr->next;
  Node *newNode = getNode(data);
  nodePtr->next = newNode;
  newNode->prev = nodePtr;
  tail = newNode;
}

void addNode2Num(int data, int num) { // 3 data pos
  if (num == 1) {
    addNode2Head(data);
    return;
  }

  Node *nodePtr = head;
  for (int i = 0; i < num - 2; i++) {
    nodePtr = nodePtr->next;
  }
  Node *newNode = getNode(data);
  if (nodePtr->next) {
    newNode->next = nodePtr->next;
    newNode->prev = nodePtr;
    nodePtr->next->prev = newNode;
  } else {
    newNode->prev = nodePtr;
    tail = newNode;
  }
  nodePtr->next = newNode;
}

int findNode(int data) { // 4 data
  Node *nodePtr = head;
  int cnt = 1;
  while (nodePtr) {
    if (nodePtr->data == data) return cnt;
    nodePtr = nodePtr->next;
    cnt++;
  }
  return -1;
}

void removeNode(int data) { // 5 data
  Node *nodePtr = head;
  while (true) {
    if (!nodePtr) return;
    if (nodePtr->data == data) break;
    nodePtr = nodePtr->next;
  }

  if (nodePtr->prev && nodePtr->next) {
    nodePtr->next->prev = nodePtr->prev;
    nodePtr->prev->next = nodePtr->next;
    return;
  }
  if (nodePtr->prev && !nodePtr->next) {
    nodePtr->prev->next = nullptr;
    tail = nodePtr->prev;
    return;
  }
  if (!nodePtr->prev && nodePtr->next) {
    nodePtr->next->prev = nullptr;
    head = nodePtr->next;
    return;
  }
  init();
}

int getList(int output[MAX_NODE]) { // 6
  Node *nodePtr = head;
  int i = 0;
  while (nodePtr) {
    output[i++] = nodePtr->data;
    nodePtr = nodePtr->next;
  }
  return i;
}

int getReversedList(int output[MAX_NODE]) { // 7
  Node *nodePtr = tail;
  int i = 0;
  while (nodePtr) {
    output[i++] = nodePtr->data;
    nodePtr = nodePtr->prev;
  }
  return i;
}

static void run() {
  while (1) {
    int cmd, data, num, cnt, i = 0;
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
      case FIND: // 4
        scanf("%d", &data);
        num = findNode(data);
        printf("%d\n", num);
        break;
      case REMOVE: // 5
        scanf("%d", &data);
        removeNode(data);
        break;
      case PRINT: // 6
        cnt = getList(output);
        while (cnt--)
          printf("%d ", output[i++]);
        printf("\n");
        break;
      case PRINT_REVERSE: // 7
        cnt = getReversedList(output);
        while (cnt--)
          printf("%d ", output[i++]);
        printf("\n");
        break;
      case END:return;
    }
  }
}

int main(void) {
  //setbuf(stdout, NULL);
  //freopen("dll_input.txt", "r", stdin);

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