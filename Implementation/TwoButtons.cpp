#include<bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int m;
  cin >> m;
  int count = 0;
  while(n>m){
    if((m&1)==1){
      count++;
      m++;
    }
    else {
      m >>= 1;
      count++;
    }
    cout << count + (n-m) << endl;
  }
}