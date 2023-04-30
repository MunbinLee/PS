#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef unsigned int ul;

int n;
vector<ul> ips;

int ip2num(const string &addr) {
  stringstream ss(addr);
  string token;
  ul num = 0;
  ul multi = 0x1000000;
  for (int i = 0; i < 4; i++) {
    getline(ss, token, '.');
    ul byte = stoul(token);
    byte *= multi;
    num += byte;
    multi /= 0x100;
  }
  return num;
}

string num2ip(ul num) {
  ul multi = 0x1000000;
  string addr;

  for (int i = 0; i < 4; i++) {
    ul byte = num / multi;
    addr += to_string(byte) + '.';
    num %= multi;
    multi /= 0x100;
  }

  addr.pop_back();
  return addr;
}

int getPrefixLen() {
  int len = 0;
  for (int i = 31; i >= 0; i--) {
    int bit = (ips[0] >> i) & 1;
    for (int j = 1; j < n; j++) {
      int otherBit = (ips[j] >> i) & 1;
      if (bit != otherBit) return len;
    }
    len++;
  }
  return len;
}

int createMask(int m) {
  int mask = 0;
  for (int i = 0; i < m; i++) {
    mask |= 1 << i;
  }
  mask <<= 32 - m;
  return mask;
}

int createAddr(int mask) {
  return ips[0] & mask;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  ips.resize(n);
  for (ul &ip: ips) {
    string s;
    cin >> s;
    ip = ip2num(s);
  }

  int m = getPrefixLen();
  int mask = createMask(m);
  int addr = createAddr(mask);

  cout << num2ip(addr) << '\n';
  cout << num2ip(mask);
  return 0;
}
