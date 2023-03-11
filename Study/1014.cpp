#include <iostream>
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

Node *start, *dest;
map<Node *, pair<double, string>> dists; // 노드 {거리, 경로}
map<string, Node *> strToNode;

void readAlabama() {
  ifstream fin;
  fin.open("C:/alabama.txt");

  int nodeCnt = 0;
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

void dijkstra() {
  ifstream fin;
  fin.open("C:/input.txt");

  string tmp;
  getline(fin, tmp, ',');
  start = strToNode[tmp];
  getline(fin, tmp, ' ');
  getline(fin, tmp);
  dest = strToNode[tmp];

  dists[start].first = 0;
  priority_queue<pair<double, Node *>> pq; // cost, Node*
  pq.emplace(0, start);

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    cost *= -1;
    pq.pop();

    for (auto i: cur->edges) {
      auto [next, nCost] = i;
      if (!dists.contains(next)) dists[next].first = INF;
      if (dists[next].first <= cost + nCost) continue;
      dists[next].first = cost + nCost;
      dists[next].second = cur->name;
      pq.emplace(-dists[next].first, next);
    }
  }
}

void output() {
  Node *parent = dest;
  vector<string> res;

  while (parent != start) {
    res.emplace_back(to_string(parent->idx) + ' ' + parent->name);
    parent = strToNode[dists[parent].second];
  }
  res.emplace_back(to_string(start->idx) + ' ' + start->name);
  for (auto &re: ranges::reverse_view(res)) {
    cout << re << '\n';
  }
  cout << dists[dest].first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  readAlabama();
  readRoad();
  dijkstra();
  output();
  return 0;
}
