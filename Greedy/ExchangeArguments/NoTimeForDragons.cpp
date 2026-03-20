/*
https://codeforces.com/problemset/gymProblem/101149/B
*/

/*
Appeared in :
2016, Samara University ACM ICPC Quarterfinal Qualification Contest
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Army{
  int a;
  int b;
};

bool cmp(Army& x ,Army& y){
  return (x.a - x.b) > (y.a - y.b);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Army> armies(n);
  for(auto& army : armies) {
    cin >> army.a >> army.b ;
  }
  sort(armies.begin(),armies.end(),cmp);
   
  return 0; 
}