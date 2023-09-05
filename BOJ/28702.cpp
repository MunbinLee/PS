#include <iostream>

using namespace std;

string FizzBuzz(int num) {
  if (num % 15 == 0) return "FizzBuzz";
  if (num % 3 == 0) return "Fizz";
  if (num % 5 == 0) return "Buzz";
  return to_string(num);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 3; i > 0; i--) {
    string s;
    cin >> s;
    if (isdigit(s[0])) {
      cout << FizzBuzz(stoi(s) + i);
      return 0;
    }
  }

  return 0;
}
