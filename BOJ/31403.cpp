#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;
    
    cout << A + B - C << '\n' << stoi(to_string(A) + to_string(B)) - C;
    
    return 0;
}
