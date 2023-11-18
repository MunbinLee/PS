#include <iostream>
#include <vector>

using namespace std;

const long MOD = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> hot_vector;
    hot_vector.reserve(300000);

    int hot_min = INT_MAX;
    int hot_max = 0;
    long pain_sum = 0;

    int N;
    cin >> N;

    while (N--) {
        int hot_input;
        cin >> hot_input;

        hot_min = min(hot_min, hot_input);
        hot_max = max(hot_max, hot_input);

        for (int hot: hot_vector) {
            int pain = max(hot_max - hot, hot - hot_min);
            pain_sum += pain;
        }

        hot_vector.emplace_back(hot_input);
        cout << pain_sum << ' ';
    }

    cout << pain_sum;

    return 0;
}
