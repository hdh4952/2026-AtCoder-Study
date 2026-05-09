#include <bits/stdc++.h>
using namespace std;

double A[4][7];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i=1 ; i<=3 ; i++) {
    vector<double> cnt(7, 0);
    for (int j=1 ; j<=6 ; j++) {
      int a; cin >> a;
      cnt[a]++;
    }
    A[i][4] = cnt[4] / 6.0;
    A[i][5] = cnt[5] / 6.0;
    A[i][6] = cnt[6] / 6.0;
  }

  vector<int> arr{4, 5, 6};
  double ans = 0;
  do {
    ans += A[1][arr[0]] * A[2][arr[1]] * A[3][arr[2]];
  } while (next_permutation(arr.begin(), arr.end()));

  cout << fixed;
  cout.precision(10);
  cout << ans;
}