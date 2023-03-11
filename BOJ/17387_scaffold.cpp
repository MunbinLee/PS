#include <iostream>
#include <vector>
#include <cmath>

#define INF 987654321
#define ll long long


using namespace std;

struct Line {
  struct Point {
    double x, y;

    bool operator<(const Point &other) const {
      if (x == other.x) return y < other.y;
      return x < other.x;
    }

    bool operator==(const Point &other) const {
      return x == other.x && y == other.y;
    }
  };

  Point point[2];
  double slope;
  double x_intercept;
  double y_intercept;

  bool operator<(const Line &other) const {
    if (point[0] == other.point[0]) return point[1] < other.point[1];
    return point[0] < other.point[0];
  }
};

Line line[2];

int CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
  ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

  temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

  if (temp > 0) return 1; // 반시계
  else if (temp == 0) return 0; // 일직선
  else if (temp < 0) return -1; // 시계
}

int solve_scaffold(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8) {
  pair<int, int> A;
  pair<int, int> B;
  pair<int, int> C;
  pair<int, int> D;
  A.first = n1;
  A.second = n2;
  B.first = n3;
  B.second = n4;
  C.first = n5;
  C.second = n6;
  D.first = n7;
  D.second = n8;

  //ABC
  int abc = CCW(A, B, C);
  //ABD
  int abd = CCW(A, B, D);
  //CDA
  int cda = CCW(C, D, A);
  //CDB
  int cdb = CCW(C, D, B);

  if (abc * abd == 0 && cda * cdb == 0) {
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);
    //first 비교가 아닌 것은 x가 같고 y가 달라서 일직선일 수 있으므로..
    if (A <= D && C <= B) {
      return 1;
    } else {
      return 0;
    }
  }


  if (abc * abd <= 0 && cda * cdb <= 0) {
    return 1;
  } else return 0;
}

bool equal(double d1, double d2) {
  return (abs(d2 - d1)) < 0.01;
}

bool lessOrEqual(double d1, double d2) {
  if (equal(d1, d2)) return true;
  return (d1 < d2);
}

double minX(int i) {
  return min(line[i].point[0].x, line[i].point[1].x);
}

double minY(int i) {
  return min(line[i].point[0].y, line[i].point[1].y);
}

double maxX(int i) {
  return max(line[i].point[0].x, line[i].point[1].x);
}

double maxY(int i) {
  return max(line[i].point[0].y, line[i].point[1].y);
}

bool betweenX(double x) {
  bool cond1 = lessOrEqual(minX(0), x) && lessOrEqual(x, maxX(0));
  bool cond2 = lessOrEqual(minX(1), x) && lessOrEqual(x, maxX(1));
  return cond1 && cond2;
}

bool betweenY(double y) {
  bool cond1 = lessOrEqual(minY(0), y) && lessOrEqual(y, maxY(0));
  bool cond2 = lessOrEqual(minY(1), y) && lessOrEqual(y, maxY(1));
  return cond1 && cond2;
}

bool solve(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8) {
  for (auto &l: line) {
    for (auto &p: l.point) {
      cin >> p.x >> p.y;
    }
  }
  line[0].point[0].x = n1;
  line[0].point[0].y = n2;
  line[0].point[1].x = n3;
  line[0].point[1].y = n4;
  line[1].point[0].x = n5;
  line[1].point[0].y = n6;
  line[1].point[1].x = n7;
  line[1].point[1].y = n8;

  for (auto &l: line) {
    sort(l.point, l.point + 2);

    // 기울기
    if (l.point[1].x - l.point[0].x != 0) {
      l.slope = (l.point[1].y - l.point[0].y) / (l.point[1].x - l.point[0].x);
    } else { // 세로 직선
      l.slope = INF;
    }

    // y 절편
    if (l.slope == 0) {
      l.y_intercept = l.point[0].y;
    } else if (l.slope == INF) {
      l.y_intercept = INF;
    } else {
      l.y_intercept = l.point[0].y - l.slope * l.point[0].x;
    }

    // x 절편
    if (l.slope == 0) {
      l.x_intercept = INF;
    } else if (l.slope == INF) {
      l.x_intercept = l.point[0].x;
    } else {
      l.x_intercept = -l.y_intercept / l.slope;
    }
  }
  sort(line, line + 2);

  // 테스트용, 두 점이 같은 경우
  if (line[0].point[0] == line[1].point[0]) return true;
  if (line[0].point[0] == line[1].point[1]) return true;
  if (line[0].point[1] == line[1].point[0]) return true;
  if (line[0].point[1] == line[1].point[1]) return true;

  // l0는 세로 직선, l1은 가로 직선
  if (line[0].slope == INF && equal(line[1].slope, 0)) {
    double x = line[0].x_intercept;
    double y = line[1].y_intercept;
    return betweenX(x) && betweenY(y);
  }

  // l1은 세로 직선, l0는 가로 직선
  if (line[1].slope == INF && equal(line[0].slope, 0)) {
    double x = line[1].x_intercept;
    double y = line[0].y_intercept;
    return betweenX(x) && betweenY(y);
  }

  // 둘 다 세로 직선
  if (line[0].slope == INF && line[1].slope == INF) {
    if (!equal(line[0].x_intercept, line[1].x_intercept)) return false;
    return lessOrEqual(line[1].point[0].y, line[0].point[1].y);
  }

  // l0만 세로 직선
  if (line[0].slope == INF) {
    double y = line[1].slope * line[0].x_intercept + line[1].y_intercept;
    return betweenY(y);
  }

  // l1만 세로 직선
  if (line[1].slope == INF) {
    double y = line[0].slope * line[1].x_intercept + line[0].y_intercept;
    return betweenY(y);
  }

  // 둘 다 가로 직선
  if (equal(line[0].slope, 0) && equal(line[1].slope, 0)) {
    if (!equal(line[0].y_intercept, line[1].y_intercept)) return false;
    return lessOrEqual(line[1].point[0].x, line[0].point[1].x);
  }

  // l0만 가로 직선
  if (equal(line[0].slope, 0)) {
    double x = (line[0].y_intercept - line[1].y_intercept) / line[1].slope;
    return betweenX(x);
  }

  // l1만 가로 직선
  if (equal(line[1].slope, 0)) {
    double x = (line[1].y_intercept - line[0].y_intercept) / line[0].slope;
    return betweenX(x);
  }

  // 기울기가 같은 두 직선
  if (equal(line[0].slope, line[1].slope)) {
    if (!equal(line[0].y_intercept, line[1].y_intercept)) return false;
    return lessOrEqual(line[1].point[0].x, line[0].point[1].x);
  }

  // 일반적인 두 직선
  double x = (line[1].y_intercept - line[0].y_intercept) / (line[0].slope - line[1].slope);
  return betweenX(x);
}

int main() {
  int cnt;
  cin >> cnt;
  while (cnt--) {
    int n1, n2, n3, n4, n5, n6, n7, n8;
    cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8;
    if (solve(n1, n2, n3, n4, n5, n6, n7, n8) != solve_scaffold(n1, n2, n3, n4, n5, n6, n7, n8)) {
      cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << '\n' << n5 << ' ' << n6 << ' ' << n7 << ' ' << n8 << '\n';
      cout << "your output: " << solve(n1, n2, n3, n4, n5, n6, n7, n8) << '\n';
      cout << "real answer: " << solve_scaffold(n1, n2, n3, n4, n5, n6, n7, n8);
      return 0;
    }
  }
  return 0;
}
