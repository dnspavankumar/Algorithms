/*
Problem Link : 

https://www.hackerrank.com/contests/icode-2015-week-one/challenges/minimum-scalar-product
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(auto& x : a) cin >> x;
  for(auto& x : b) cin >> x;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end(),greater<int>());
  int ans = 0;
  for(int i = 0; i < n; i++) ans += (a[i]*b[i]);
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}