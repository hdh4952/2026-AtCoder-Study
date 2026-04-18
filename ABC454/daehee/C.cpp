#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300010];
vector<int> vis(300010, false);

int dfs(int now) {
  vis[now] = true;
  int ret = 1;
  for (const auto& nxt : adj[now]) {
    if (vis[nxt]) continue;
    ret += dfs(nxt);
  }

  return ret;

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M; cin >> N >> M;
  
  for (int i=0 ; i<M ; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }


  cout << dfs(1);
}