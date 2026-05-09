#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll DIV = 998244353;

string s;
ll dp[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  for (char c : s) {
    int idx = c - 'a';
    dp[idx] = (dp[0] + dp[1] + dp[2] + 1) % DIV;
  }

  cout << (dp[0] + dp[1] + dp[2]) % DIV;
}