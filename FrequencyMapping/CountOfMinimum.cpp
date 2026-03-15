#include<bits/stdc++.h>
using namespace std;

long long countOfMin(vector<int>& a) {
  int cnt = 0;
  //stl function to find minimum element
  int mn = *min_element(a.begin(),a.end());
  for(auto& x : a) cnt += (x==mn);
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a (n);
  for(auto& x : a) cin >> x;
  cout << countOfMin(a) << endl;
  return 0;
}

/*
Since we are maintaining a count of a single element we just requirea a variable what if we had to count multiple items
Lets see in the next one
*/