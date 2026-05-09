#include <bits/stdc++.h>
using namespace std;

const int DIV = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.length();

  vector<long long> v;
  int j = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      v.push_back(i - j + 1);
      j = i + 1;
    }
  }
  v.push_back(n - j);

  long long ans = 0;
  for (auto& i : v) ans = (ans + (i * (i + 1) / 2) % DIV) % DIV;
  cout << ans;
}