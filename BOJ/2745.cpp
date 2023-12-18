#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char, int> digits;

    for (int i = 0; i <= 9; i++) {
        digits[i + '0'] = i;
    }

    for (int i = 10; i <= 35; i++) {
        digits[i - 10 + 'A'] = i;
    }

    string N;
    int B;

    cin >> N >> B;

    int coefficient = 1;
    int answer = 0;

    for (int i = N.size() - 1; i >= 0; i--) {
        answer += digits[N[i]] * coefficient;
        coefficient *= B;
    }

    cout << answer;

    return 0;
}
