#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 998244353;

ll dp[3];
vector<char> cand{'a', 'b', 'c'};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string S; cin >> S;
  for (const auto& ch : S) {
    dp[ch - 'a']++;
    dp[ch - 'a'] %= MOD;
    for (const auto& c : cand) {
      if (ch == c) continue;
      dp[ch - 'a'] += dp[c - 'a'];
      dp[ch - 'a'] %= MOD;
    }
  }

  cout << (((dp[0] + dp[1]) % MOD) + dp[2]) % MOD;
  
}