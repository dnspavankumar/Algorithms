/*
You are given an array A of N integers. Calculate the sum of A[i] + A[j] + A[k] for all triplets (i, j, k) such that 0 ≤ i < j < k ≤ N-1.
Print the final answer modulo 10^9 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int nC2(int n) {
  return ((n*(n-1))>>1);
}
int TripletContribution(vector<int>& a) {
  int n = a.size();
  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    ans += a[i] * (nC2(n-1));
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  cout << TripletContribution(a) << endl;
  return 0;
}

/*
This can be extended further like lets say u wanna find the contribution of an element in 
Quadrupulets then with every number u gonna need 3 more numbers that means
You should choose 3 numbers from n-1 numbers to find the contribution of that particular number in the quadrupulets 
*/