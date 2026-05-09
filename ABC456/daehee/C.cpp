#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string S; cin >> S;
  ll ans = 0;
  ll cnt = 1;
  for (int i=0 ; i+1<S.length() ; i++) {
    if (S[i] == S[i+1]) {
      ans += ((cnt * (cnt+1)/2)%MOD);
      ans %= MOD;
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  ans += ((cnt * (cnt+1) / 2)%MOD);
  ans %= MOD;

  cout << ans;
}