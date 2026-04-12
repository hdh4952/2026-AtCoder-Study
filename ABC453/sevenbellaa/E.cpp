#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 200001, MOD = 998244353;
int N, ans, l, r, fact[N_MAX], imos[N_MAX];

int comb(int n, int x) { return fact[n] / (fact[x] * fact[n - x] % MOD) % MOD; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  fact[0] = fact[1] = 1;
  for (int i = 2; i < N_MAX; i++) fact[i] = fact[i - 1] * i % MOD;

  for (int i = 0; i < N; i++) {
    cin >> l >> r;
    imos[l]++;
    imos[r + 1]--;
  }

  for (int i = 1; i < N; i++) imos[i] += imos[i - 1];
  for (int i = 1; i < N; i++) {
    if (imos[i] >= i) ans += comb(imos[i], i);
    cout << ans << ' ';
  }
  cout << comb(2, 2);
}

//  998244353