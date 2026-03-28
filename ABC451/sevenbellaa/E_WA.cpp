#include <bits/stdc++.h>
using namespace std;

int N, dist[3003][3003];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 1; i < N; i++) {
    for (int j = i + 1; j <= N; j++) cin >> dist[i][j];
  }

  for (int i = 1; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      bool flag = false;
      for (int k = i + 1; k < j; k++) {
        if (dist[i][k] + dist[k][j] == dist[i][j]) flag = true;
      }
      if (!flag && j - i > 1) {
        cout << i << j;
        cout << "No";
        return 0;
      }
    }
  }

  cout << "Yes";
}