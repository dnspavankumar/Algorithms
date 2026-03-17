/*
Problem Link :
https://leetcode.com/problems/stone-game-vi/description/

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Stone {
  int a;
  int b;
};

bool comparator(Stone& A,Stone& B) {
  return (A.b + A.a) > (B.b + B.a);
}

void solve() {
  int n;
  cin >> n;
  vector<Stone> stones(n);
  for(auto& stone : stones) cin >> stone.a >> stone.b ;
  int alice = 0;
  int bob = 0;
  sort(stones.begin(),stones.end(),comparator);
  for(int i = 0 ; i < n ; i++) {
    (i&1) ? bob += stones[i].a : alice += stones[i].b;
  }
  if(alice > bob) cout << "Alice" << endl;
  else if(alice < bob) cout << "Bob" << endl;
  else cout << "Draw" << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}