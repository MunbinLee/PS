#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  stack<int> st;
  int k;
  cin >> k;
  while (k--) {
    int tmp;
    cin >> tmp;
    if (tmp == 0) st.pop();
    else st.emplace(tmp);
  }

  int sum = 0;
  while (!st.empty()) {
    sum += st.top();
    st.pop();
  }
  cout << sum;
  return 0;
}
