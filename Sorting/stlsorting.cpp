#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  /****************************/
  sort(a.begin(),a.end());      // stl function to sort a given vector
  /****************************/
  for(auto& x : a) cout << x << endl;
  return 0;
}