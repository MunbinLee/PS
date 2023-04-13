#include <string>
#include <vector>
#include <tuple>

using namespace std;

int n;
vector<tuple<string, int, int>> plans;

int timeToInt(string time) {
  int h = stoi(time.substr(0, 2));
  int m = stoi(time.substr(3, 2));
  return h * 60 + m;
}

vector<string> solution(const vector<vector<string>> &p) {
  n = p.size();
  plans.resize(n);
  for (int i = 0; i < n; i++) {
    plans[0] = {p[0], 1, 1};

  }
  vector<string> answer;
  return answer;
}