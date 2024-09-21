#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<int> fruits(N);
    for (int& fruit : fruits) {
        cin >> fruit;
    }
    
    int lo = 0;
    int maxLen = 1;
    array<int, 10> contains {};
    contains[fruits[0]] = 1;
    int types = 1;
    
    for (int hi = 1; hi < N; hi++) {
        int fruit = fruits[hi];
        
        if (!contains[fruit] && types == 2) {
            while (types == 2) {
                contains[fruits[lo]]--;
                if (contains[fruits[lo]] == 0) types = 1;
                lo++;
            }
        }
        
        if (!contains[fruit]) {
            types++;
        }
        
        contains[fruit]++;
        int len = hi - lo + 1;
        maxLen = max(maxLen, len);
    }
    
    cout << maxLen;
    
    return 0;
}
