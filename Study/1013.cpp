#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <fstream>
#include <ranges>

#define INF 987654321

using namespace std;

struct Node {
  int idx{};
  string name;
  double lat{}, lon{};
  map<Node *, double> edges;
};

int nodeCnt;
Node *start, *dest;
vector<Node *> nodes;
map<Node *, pair<double, string>> dists; // 노드 {거리, 경로}
map<string, Node *> strToNode;
map<int, int> parent;

void setParent() {
  for (int i = 1; i <= nodeCnt; i++) {
    parent[i] = i;
  }
}

int getParent(int i) {
  if (parent[i] == i) return i;
  return parent[i] = getParent(parent[i]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

bool isCycle(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b) return true;
  else return false;
}

void readAlabama() {
  ifstream fin;
  fin.open("C:/alabama.txt");

  while (true) {
    string name, tmp;
    if (!getline(fin, name, '\t')) break;
    Node *pNode = new Node;
    pNode->idx = nodeCnt++;
    pNode->name = name;
    getline(fin, tmp, '\t');
    pNode->lon = stod(tmp);
    getline(fin, tmp);
    pNode->lat = stod(tmp);
    strToNode[name] = pNode;
    nodes.emplace_back(pNode);
  }
}

// 주어진 디그리 값을 라디안 값으로 변환
double deg2rad(double deg) {
  return deg * M_PI / 180;
}

// 주어진 라디안 값을 디그리 값으로 변환
double rad2deg(double rad) {
  return rad * 180 / M_PI;
}

double calcDist(double lat1, double lon1, double lat2, double lon2) {
  double theta = lon1 - lon2;
  double dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  dist = dist * 1.609344; // 마일-킬로미터 변환
  dist = dist * 1000.0; // 킬로미터-미터 변환
  return dist;
}

void readRoad() {
  ifstream fin;
  fin.open("C:/road.txt");

  while (true) {
    string name1, name2;
    if (!getline(fin, name1, '\t')) break;
    getline(fin, name2);
    Node *pNode1 = strToNode[name1];
    Node *pNode2 = strToNode[name2];
    double dist = calcDist(pNode1->lat, pNode1->lon, pNode2->lat, pNode2->lon);
    pNode1->edges[pNode2] = dist;
    pNode2->edges[pNode1] = dist;
  }
}

void kruskal() {
}

void output() {
  for (int i = 0; i < nodes.size(); i++) {
    cout << i << ' ' << nodes[i]->lon << ' ' << nodes[i]->lat << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  readAlabama();
  readRoad();
//  kruskal();
  output();
  return 0;
}
