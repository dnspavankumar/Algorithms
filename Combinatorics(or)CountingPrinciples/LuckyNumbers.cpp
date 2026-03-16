/*
https://codeforces.com/problemset/problem/630/C
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int LuckyNumbers(int n) {
  return ((1 << (n+1)) - 2);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << LuckyNumbers(n) << endl;
  return 0;
}

/*
The idea of removing duplicates
we are given n blanks 
The n blanks have 2 choices each
But if we try to fill it this way

For n=2
78
87
77
88
77
88

Because this assumes that both 7s and both 8s are unique

Therefore we must make sure that the elements are added only once which have these kind of combinations

In 6 combinations 2 are duplicates for 2^2
*/