#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, double> scoreMap = {
            {"A+", 4.5},
            {"A0", 4.0},
            {"B+", 3.5},
            {"B0", 3.0},
            {"C+", 2.5},
            {"C0", 2.0},
            {"D+", 1.5},
            {"D0", 1.0},
            {"F", 0.0},
    };

    string ignored, grade;
    double credit;
    double creditSum = 0;
    double scoreSum = 0;

    while (cin >> ignored >> credit >> grade) {
        if (grade == "P") continue;
        creditSum += credit;
        scoreSum += scoreMap[grade] * credit;
    }

    cout << scoreSum / creditSum;

    return 0;
}
