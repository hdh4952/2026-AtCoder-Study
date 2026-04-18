#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M; cin >> N >> M;
  vector<int> arr(N);
  for (auto &i : arr) cin >> i;
  sort(arr.begin(), arr.end());

  bool flag = false;
  for (int i=0 ; i<N-1 ; i++) {
    if (arr[i] == arr[i+1]) {
      flag = true;
      cout << "No\n";
      break;
    }
  }

  if (!flag) cout << "Yes\n";

  set<int> s;
  for (int i=0 ; i<N ; i++) s.insert(arr[i]);
  if (s.size() >= M) cout << "Yes";
  else cout << "No";
}