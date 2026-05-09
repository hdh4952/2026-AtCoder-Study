#include <bits/stdc++.h>
using namespace std;

auto failure(string_view sv) {
  vector<int> F(sv.size());
  for (int i = 1, j = 0; i < (int)sv.size(); i++) {
    while (j > 0 && sv[i] != sv[j]) j = F[j - 1];
    if (sv[i] == sv[j]) F[i] = ++j;
  }
  return F;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  int sn = s.size(), tn = t.size();

  int rep = (tn + sn - 1) / sn + 1;
  string sv = t + '#';
  while (rep--) sv += s;

  auto F = failure(sv);

  vector<int> nxt(sn, -1), indegree(sn);
  for (int i = 0; i < sn; i++) {
    if (F[tn * 2 + i] == tn) {
      int nx = (i + tn) % sn;
      nxt[i] = nx;
      indegree[nx]++;
    }
  }

  int ans = 0;
  vector<int> vis(sn);
  for (int i = 0; i < sn; i++) {
    if (vis[i] || indegree[i]) continue;

    vis[i] = 1;
    int cur = i, cnt = 0;
    while (nxt[cur] != -1) {
      ++cnt;
      cur = nxt[cur];
      vis[cur] = 1;
    }
    ans = max(ans, cnt);
  }

  if (ranges::any_of(vis, [](int v) { return !v; }))
    cout << -1;
  else
    cout << ans;
}