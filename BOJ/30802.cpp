#include <iostream>
#include <array>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int N;
    cin >> N;
    
    array<int, 6> sizes {};
    for (int& size : sizes) {
        cin >> size;
    }
    
    int T, P;
    cin >> T >> P;
    
    int tBundle = 0;
    for (int size : sizes) {
        if (!size) {
            continue;
        }
        
        tBundle += (size - 1) / T + 1;
    }
    
    cout << tBundle << '\n' << N / P << ' ' << N % P;
    
    return 0;
}
