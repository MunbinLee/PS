#include <iostream>

using namespace std;

int main() {
    int h, b, c, s;
    cin >> h >> b >> c >> s;
    printf("%.1f MB", (double) h * b * c * s / 1024 / 1024 / 8);
    return 0;
}
