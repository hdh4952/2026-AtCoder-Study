#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  cin >> x;
  if (x < 3 || x > 18)
    cout << "No";
  else
    cout << "Yes";
}