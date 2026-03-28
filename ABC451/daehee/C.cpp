#include <bits/stdc++.h>
using namespace std;

void solve() {
  int Q; cin >> Q;
  priority_queue<int, vector<int>, greater<>> pq;

  while (Q--) {
    int q, h; cin >> q >> h;
    if (q == 1) {
      pq.push(h);
    }

    if (q == 2) {
      while (!pq.empty() && pq.top() <= h) pq.pop();
    }
    
    cout << pq.size() << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();
}