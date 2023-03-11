#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <tuple>

#define MAX_SOLDIER 100000
#define MAX_TEAM 5
#define MAX_SCORE 5

struct Node {
  int id, team;
  Node *next, *prev;
};

Node node[MAX_SOLDIER + 1];
Node *head[MAX_TEAM + 1][MAX_SCORE + 1];
Node *tail[MAX_TEAM + 1][MAX_SCORE + 1];

void assert() {
  printf("assert\n");
}

void init() {
  for (int i = 1; i <= MAX_TEAM; i++) {
    for (int j = 1; j <= MAX_SCORE; j++) {
      head[i][j] = nullptr;
      tail[i][j] = nullptr;
    }
  }
}

Node *createNode(int id, int team) {
  Node *pNode = &node[id];
  pNode->id = id;
  pNode->team = team;
  pNode->next = nullptr;
  pNode->prev = nullptr;
  return pNode;
}

void hire(int mID, int mTeam, int mScore) {
  if (!head[mTeam][mScore] and tail[mTeam][mScore]) assert();
  if (head[mTeam][mScore] and !tail[mTeam][mScore]) assert();

  Node *pNode = createNode(mID, mTeam);
  if (!head[mTeam][mScore]) {
    head[mTeam][mScore] = pNode;
    tail[mTeam][mScore] = pNode;
  } else {
    tail[mTeam][mScore]->next = pNode;
    pNode->prev = tail[mTeam][mScore];
    tail[mTeam][mScore] = pNode;
  }
}

std::pair<int, int> isHead(int id) {
  for (int i = 1; i <= MAX_TEAM; i++) {
    for (int j = 1; j <= MAX_SCORE; j++) {
      if (head[i][j] && head[i][j]->id == id) return {i, j};
    }
  }
  return {-1, -1};
}

std::pair<int, int> isTail(int id) {
  for (int i = 1; i <= MAX_TEAM; i++) {
    for (int j = 1; j <= MAX_SCORE; j++) {
      if (tail[i][j] && tail[i][j]->id == id) return {i, j};
    }
  }
  return {-1, -1};
}

void fire(int mID) {
  Node *pNode = &node[mID];
  if (pNode->next) pNode->next->prev = pNode->prev;
  if (pNode->prev) pNode->prev->next = pNode->next;

  int team, score;
  std::tie(team, score) = isHead(mID);
  if (team != -1) head[team][score] = head[team][score]->next;
  std::tie(team, score) = isTail(mID);
  if (team != -1) tail[team][score] = tail[team][score]->prev;
}

void updateSoldier(int mID, int mScore) {
  int mTeam = node[mID].team;
  fire(mID);
  hire(mID, mTeam, mScore);
}

void moveScore(int team, int from, int to) {
  if (to > MAX_SCORE || to <= 0) return;
  if (!head[team][from]) return;
  if (tail[team][to]) {
    tail[team][to]->next = head[team][from];
    head[team][from]->prev = tail[team][to];
  } else head[team][to] = head[team][from];
  tail[team][to] = tail[team][from];
  head[team][from] = nullptr;
  tail[team][from] = nullptr;
}

void updateTeam(int mTeam, int mChangeScore) {
  if (mChangeScore > 0) {
    for (int i = MAX_SCORE - 1; i >= 0; i--) {
      moveScore(mTeam, i, i + mChangeScore);
    }
  } else {
    for (int i = 2; i <= MAX_SCORE; i++) {
      moveScore(mTeam, i, i + mChangeScore);
    }
  }
}

int bestSoldierInScore(int mTeam, int mScore) {
  int id = -1;
  Node *pNode = head[mTeam][mScore];
  while (pNode) {
    if (pNode->id > id) id = pNode->id;
    pNode = pNode->next;
  }
  return id;
}

int bestSoldier(int mTeam) {
  for (int i = MAX_SCORE; i > 0; i--) {
    int id = bestSoldierInScore(mTeam, i);
    if (id != -1) return id;
  }
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
      case CMD_INIT:
        init();
        isCorrect = true;
        break;
      case CMD_HIRE:
        scanf("%d %d %d", &mID, &mTeam, &mScore);
        hire(mID, mTeam, mScore);
        break;
      case CMD_FIRE:
        scanf("%d", &mID);
        fire(mID);
        break;
      case CMD_UPDATE_SOLDIER:
        scanf("%d %d", &mID, &mScore);
        updateSoldier(mID, mScore);
        break;
      case CMD_UPDATE_TEAM:
        scanf("%d %d", &mTeam, &mChangeScore);
        updateTeam(mTeam, mChangeScore);
        break;
      case CMD_BEST_SOLDIER:
        scanf("%d", &mTeam);
        userAns = bestSoldier(mTeam);
        scanf("%d", &ans);
        if (userAns != ans) {
          isCorrect = false;
        }
        break;
      default:
        isCorrect = false;
        break;
    }
  }

  return isCorrect;
}

int main() {
  setbuf(stdout, nullptr);
  //freopen("sample_input.txt", "r", stdin);

  int T, MARK;
  scanf("%d %d", &T, &MARK);

  for (int tc = 1; tc <= T; tc++) {
    int score = run() ? MARK : 0;
    printf("#%d %d\n", tc, score);
  }

  return 0;
}