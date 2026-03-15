#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int target;
  cin >> target;
  vector<int> a(n);
  for(auto& x : a) cin >> x;

  for(int i = 0 ; i < n ; i++) {
    if(a[i]==target) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}