/*
https://atcoder.jp/contests/abc186/tasks/abc186_d
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end());

  long long prefixSum = 0;
  long long ans = 0;

  for(int i = 0; i < n; i++) {
    ans += a[i] * i - prefixSum;
    prefixSum += a[i];
  }

  cout << ans << endl;
  return 0;
}