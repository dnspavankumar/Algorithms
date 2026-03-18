//Problem Link
/*
https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1
*/

#include<bits/stdc++.h>
using namespace std;

int SumOfAllSubarrays(vector<int>& a) {
  int sum = 0;
  int n = a.size();
  for(int i = 0 ; i < n ; i++) {
    sum += (a[i] * (n-i) * (i+1) );
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  cout << SumOfAllSubarrays(a) << endl;
  return 0;
}
