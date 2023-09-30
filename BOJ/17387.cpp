#include <iostream>

#define INF 987654321

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

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto &l: line) {
    for (auto &p: l.point) {
      cin >> p.x >> p.y;
    }
  }

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
}

bool equal(double d1, double d2) {
  return (abs(d2 - d1)) < 0.0000001;
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

bool DoLinesIntercept() {
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
  input();
  cout << DoLinesIntercept();
  return 0;
}
