#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int numerator = a * d + b * c;
    int denominator = b * d;

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    cout << numerator << ' ' << denominator;

    return 0;
}
