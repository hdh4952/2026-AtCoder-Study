#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int answer = 0;
int N;
vector<ll> arr(20);

void search(ll now, int k, int cnt) {
  if (k == N) {
    answer = max(answer, cnt);
    return;
  }

  bool isCnt = (now < 0 && now + arr[k] > 0);
  search(now + arr[k], k+1, cnt + isCnt);
  isCnt = (now > 0 && now - arr[k] < 0);
  search(now - arr[k], k+1, cnt + isCnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  
  ll now = 5;
  for (int i=0 ; i<N ; i++) {
    cin >> arr[i];
    arr[i] *= 10;
  }
  search(now, 0, 0);
  cout << answer;
}