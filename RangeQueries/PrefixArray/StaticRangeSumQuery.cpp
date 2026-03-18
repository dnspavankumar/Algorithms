/*
https://cses.fi/problemset/task/1646
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for(auto& x : a ) cin >> x;
  // build prefix sum
  vector<int> prefixSum(n+1,0);
  for(int i = 0 ; i < n ; i++) {
    prefixSum[i] = prefixSum[i-1] + a[i-1];
  }
  while(q--) {
    int l , r;
    cin >> l >> r;
    l--;
    r--;
    cout << prefixSum[r+1] - prefixSum[l] << endl;
  }
  return 0;
}