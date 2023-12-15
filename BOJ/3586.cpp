#include <iostream>
#include <stack>
#include <numeric>
#include <vector>

#define int long long

using namespace std;

// (ax + b) / (cx+ d)
struct Fraction {

    // ax + b
    struct Polynomial {
        int coefficient;
        int constant;

        explicit Polynomial(int constant) :
                coefficient(0),
                constant(constant) {};

        Polynomial(int coefficient, int constant) :
                coefficient(coefficient),
                constant(constant) {};

        Polynomial operator+(const Polynomial &other) const {
            return {
                    coefficient + other.coefficient,
                    constant + other.constant
            };
        }

        Polynomial operator-() const {
            return {
                    -coefficient,
                    -constant
            };
        }

        Polynomial operator*(const Polynomial &other) const {
            return {
                    this->coefficient * other.constant + this->constant * other.coefficient,
                    this->constant * other.constant
            };
        };
    };

    Polynomial numerator;
    Polynomial denominator;

    explicit Fraction(int constant) :
            numerator(Polynomial(constant)),
            denominator(Polynomial(1)) {};

    Fraction(int numeratorCoefficient, int numeratorConstant,
             int denominatorCoefficient = 0, int denominatorConstant = 1) :
            numerator(Polynomial(numeratorCoefficient, numeratorConstant)),
            denominator(Polynomial(denominatorCoefficient, denominatorConstant)) {};

    Fraction(Polynomial numerator, Polynomial denominator) :
            numerator(numerator),
            denominator(denominator) {};

    Fraction operator+(const Fraction &other) const {
        return {
                this->numerator * other.denominator + this->denominator * other.numerator,
                this->denominator * other.denominator
        };
    }

    Fraction operator-() const {
        return {
                -this->numerator,
                this->denominator
        };
    }

    Fraction operator-(const Fraction &other) const {
        return this->operator+(-other);
    }

    Fraction operator*(const Fraction &other) const {
        return {
                this->numerator * other.numerator,
                this->denominator * other.denominator
        };
    }

    Fraction operator/(const Fraction &other) const {
        return this->operator*({other.denominator, other.numerator});
    }
};

stack<Fraction> st;
string token;
vector<pair<int, int>> denominators;

auto calculate(auto &a, auto &b, auto &oper) {
    if (oper == "+") return a + b;
    if (oper == "-") return a - b;
    if (oper == "*") return a * b;
    return a / b;
}

void saveDenominator(Fraction::Polynomial &denominator) {
    if (denominator.coefficient == 0) return;

    denominators.emplace_back(denominator.coefficient, denominator.constant);
}

string solve() {
    while (cin >> token) {
        if (token == "X") {
            st.emplace(1, 0);
            continue;
        }

        if (isdigit(token[0])) {
            st.emplace(stoi(token));
            continue;
        }

        auto b = st.top();
        st.pop();
        auto a = st.top();
        st.pop();

        auto result = calculate(a, b, token);
        saveDenominator(result.denominator);
        st.emplace(result);
    }

    auto equation = st.top();
    int numerator = equation.numerator.constant;
    int denominator = equation.numerator.coefficient;

    if (numerator == 0 && denominator == 0) return "MULTIPLE";
    if (denominator == 0) return "NONE";

    int sign = (numerator > 0) ^ (denominator < 0) ? -1 : 1;
    numerator = sign * abs(numerator);
    denominator = abs(denominator);

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    for (auto [coefficient, constant]: denominators) {
        if (1.0 * coefficient * numerator / denominator + constant == 0) return "NONE";
    }

    return "X = " + to_string(numerator) + "/" + to_string(denominator);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();

    return 0;
}
