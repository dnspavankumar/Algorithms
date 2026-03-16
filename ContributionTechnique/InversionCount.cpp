/*
In a village, cartographer Aria maps N landmarks with heights A[i]. For every subarray (path segment i≤j), count "shadowed crossings" (inversions: p<q, A[p]>A[q]). Sum these across all subarrays.
Input: N (≤1000), then A[0..N-1].
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int mod = 1e9 +7 ;

int InvCnt(vector<int> & a) {
  int n = a.size();
  int count = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = i+1 ; j < n ; j++) {
      if(a[i]>a[j]){
        //calculate contribution of a[i] and a[j] in all subarrays
        count += ((i+1)*(n-j))%mod;
      }
    }
  }
  return count%mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a (n);
  for(auto& x : a) cin >> x;
  cout << InvCnt(a) << endl;
  return 0;
}


/*
Using this start and end point technique we can calculate the 
Contribution of any thing which we consider as an atom 

The atom can be a single element

Or in this case it can be an inversion

*/