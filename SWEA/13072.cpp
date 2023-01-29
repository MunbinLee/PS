#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

const int MIN_SCORE = 1;
const int MAX_SCORE = 5;
const int MAX_TEAM = 5;
const int MAX_NODE = 100000;

struct Node {
  int key, team;
  Node *next, *prev;
};

Node node[MAX_NODE + 1];
Node *head[MAX_TEAM + 1][MAX_SCORE + 1];
Node *tail[MAX_TEAM + 1][MAX_SCORE + 1];

Node *createNode(int key, int team, int score) {
  Node *pNode = &node[key];
  pNode->key = key;
  pNode->team = team;
  pNode->next = nullptr;
  pNode->prev = nullptr;
  return pNode;
}

void moveScore(int team, int from, int to) {
  Node **fromHead = &head[team][from];
  Node **fromTail = &tail[team][from];
  Node **toHead = &head[team][to];
  Node **toTail = &tail[team][to];

  if (*toTail) (*toTail)->next = *fromHead;
  else *toHead = *fromHead;

  if (*fromHead) (*fromHead)->prev = *toTail;
  if (*fromTail) *toTail = *fromTail;

  *fromHead = nullptr;
  *fromTail = nullptr;
}

void init() {
  for (int team = 1; team <= MAX_TEAM; team++) {
    for (int score = 1; score <= MAX_SCORE; score++) {
      head[team][score] = nullptr;
      tail[team][score] = nullptr;
    }
  }
}

void hire(int mID, int mTeam, int mScore) {
  Node *pNode = createNode(mID, mTeam, mScore);
  Node **pHead = &head[mTeam][mScore];
  Node **pTail = &tail[mTeam][mScore];

  if (!*pHead) *pHead = pNode;
  else {
    pNode->prev = *pTail;
    (*pTail)->next = pNode;
  }
  *pTail = pNode;
}

void fire(int mID) {
  Node *pNode = &node[mID];
  int team = pNode->team;

  Node **pHead = nullptr;
  Node **pTail = nullptr;
  for (int score = MIN_SCORE; score <= MAX_SCORE; score++) {
    if (pNode == head[team][score]) pHead = &head[team][score];
    if (pNode == tail[team][score]) pTail = &tail[team][score];
  }

  if (pHead) *pHead = (*pHead)->next;
  else pNode->prev->next = pNode->next;

  if (pTail) *pTail = (*pTail)->prev;
  else pNode->next->prev = pNode->prev;
}

void updateSoldier(int mID, int mScore) {
  int team = node[mID].team;
  fire(mID);
  hire(mID, team, mScore);
}

void updateTeam(int mTeam, int mChangeScore) {
  if (mChangeScore > 0) {
    for (int to = MAX_SCORE; to > MIN_SCORE; to--) {
      int from = to - mChangeScore;
      if (from < MIN_SCORE) break;
      moveScore(mTeam, from, to);
    }
  } else {
    for (int to = MIN_SCORE; to < MAX_SCORE; to++) {
      int from = to - mChangeScore;
      if (from > MAX_SCORE) break;
      moveScore(mTeam, from, to);
    }
  }
}

int bestSoldier(int mTeam) {
  int maxKey = 0;
  for (int score = MAX_SCORE; score >= MIN_SCORE; score--) {
    Node *pnode = head[mTeam][score];
    while (pnode) {
      if (pnode->key > maxKey) {
        maxKey = pnode->key;
      }
      pnode = pnode->next;
    }
    if (maxKey != 0) break;
  }
  return maxKey;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run() {
  int numQuery;

  int mID, mTeam, mScore, mChangeScore;

  int userAns, ans;

  bool isCorrect = false;

  scanf("%d", &numQuery);

  for (int i = 0; i < numQuery; ++i) {
    int cmd;
    scanf("%d", &cmd);
    switch (cmd) {
      case CMD_INIT:init();
        isCorrect = true;
        break;
      case CMD_HIRE:scanf("%d %d %d", &mID, &mTeam, &mScore);
        hire(mID, mTeam, mScore);
        break;
      case CMD_FIRE:scanf("%d", &mID);
        fire(mID);
        break;
      case CMD_UPDATE_SOLDIER:scanf("%d %d", &mID, &mScore);
        updateSoldier(mID, mScore);
        break;
      case CMD_UPDATE_TEAM:scanf("%d %d", &mTeam, &mChangeScore);
        updateTeam(mTeam, mChangeScore);
        break;
      case CMD_BEST_SOLDIER:scanf("%d", &mTeam);
        userAns = bestSoldier(mTeam);
        scanf("%d", &ans);
        if (userAns != ans) {
          isCorrect = false;
        }
        break;
      default:isCorrect = false;
        break;
    }
  }

  return isCorrect;
}

int main() {
  setbuf(stdout, NULL);
  //freopen("sample_input.txt", "r", stdin);

  int T, MARK;
  scanf("%d %d", &T, &MARK);

  for (int tc = 1; tc <= T; tc++) {
    int score = run() ? MARK : 0;
    printf("#%d %d\n", tc, score);
  }

  return 0;
}