#include <bits/stdc++.h>
using namespace std;

long long concat(long long a, long long b) {
  long long tmp = b, cnt = 0;
  while (tmp > 0) {
    tmp /= 10;
    cnt++;
  }
  return a * pow(10, cnt) + b;
}

vector<int> part;

void make_num(long long prev) {
  for (int i = 0; i < 30; i++) {
    long long nx = concat(prev, part[i]);
    if (nx <= (int)1e9) {
      part.push_back(nx);
      make_num(nx);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < 30; i++) part.push_back(1 << i);
  for (int i = 0; i < 30; i++) make_num(part[i]);

  sort(part.begin(), part.end());
  part.erase(unique(part.begin(), part.end()), part.end());

  int idx;
  cin >> idx;
  cout << part[idx - 1];
}