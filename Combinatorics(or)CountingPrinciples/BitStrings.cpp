/*
Problem Link

https://cses.fi/problemset/task/1617

*/

/*
Solution :
The number n is the number of blanks to fill 
The number of available choices to fill these blanks is 0 or 1
Hence the number of ways you can fill these blanks is 2^n
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 +7 ;
// modular exponentiation
int binpow(int a,int b){
  int res = 1;
  while(b) {
    if(b&1) res = (res*a)%mod;
    a = a*a;
  }
  return res;
}
// since the values are large any other things like builtin pow function or right shifts wont work coz it may exceed 32 bits also
int BitStrings(int n) {
  return (binpow(2,n)) % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << BitStrings(n) << endl;
  return 0;
}