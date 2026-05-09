#include <bits/stdc++.h>
using namespace std;

auto failure(string_view sv) {
  vector<int> f(sv.size());
  for (int i = 1, j = 0; i < (int)sv.size(); i++) {
    while (j > 0 && sv[i] != sv[j]) j = f[j - 1];
    if (sv[i] == sv[j]) f[i] = ++j;
  }
  return f;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  int sn = s.size(), tn = t.size();

  // Step 1: 각 시작점 i (mod |s|) 에서 t가 s^∞에서 매칭되는지 판별
  // t + '#' + s를 (ceil(|t|/|s|) + 1)번 반복한 문자열에 KMP
  int reps = (tn + sn - 1) / sn + 1;
  string text = t + '#';
  for (int i = 0; i < reps; i++) text += s;

  auto F = failure(text);

  // Step 1.5: 그래프 구축 — nxt[i] = t가 매칭되면 다음 시작점, 아니면 -1
  vector<int> nxt(sn, -1);
  for (int i = tn + 1; i < (int)text.size(); i++) {
    if (F[i] == tn) {
      int start = (i - tn + 1 - (tn + 1)) % sn;
      nxt[start] = (start + tn) % sn;
    }
  }

  // Step 2: 체인 따라가며 최장 경로 / 사이클 탐지
  // color: 0=미방문, 1=탐색중, 2=완료
  vector<int> color(sn, 0), dp(sn, 0);
  int ans = 0;

  for (int i = 0; i < sn; i++) {
    if (color[i] != 0) continue;

    vector<int> path;
    int cur = i;
    while (cur != -1 && color[cur] == 0) {
      color[cur] = 1;
      path.push_back(cur);
      cur = nxt[cur];  // -1이면 간선 없음 → 체인 끝
    }

    if (cur != -1 && color[cur] == 1) {
      cout << -1;
      return 0;
    }

    for (int k = (int)path.size() - 1; k >= 0; k--) {
      int node = path[k];
      if (nxt[node] == -1)
        dp[node] = 0;
      else
        dp[node] = 1 + (color[nxt[node]] == 2 ? dp[nxt[node]] : 0);
      color[node] = 2;
      ans = max(ans, dp[node]);
    }
  }

  cout << ans;
}