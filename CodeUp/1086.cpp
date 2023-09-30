#include <iostream>

using namespace std;

int main() {
  int w, h, b;
  cin >> w >> h >> b;
  printf("%.2f MB", (double) w * h * b / 1024 / 1024 / 8);
  return 0;
}
