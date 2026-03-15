#include<bits/stdc++.h>

using namespace std;


int firstIndexOfMin(vector<int>& a) {
  int ans = INT_MAX;
  for(int i = 0 ; i < a.size() ; i++) {
    if(a[i] < a[ans]) ans = i;
  }
  return ans;
}
int LastIndexOfMin(vector<int>& a) {
  int ans = INT_MAX;
  for(int i = 0 ; i < a.size() ; i++) {
    if(a[i] <= a[ans]) ans = i;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  return 0; 
}