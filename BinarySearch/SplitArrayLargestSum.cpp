#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

/*
Step 1:
Define expense budget and optimand for the monotonic function

Expense : number of parts required
Budget : The constraint is that is stopping you from spending extra parts which is k
         You are not supposed to split more than k parts therefore k acts as the budget
Optimand : what are u optimizing upon (finding min or max) => We are optimizing upon the sum
           We are trying to put the sum <= optimand to see if that sum is available or not

*/
bool greedy(vector<int>& seq,int optimand,int budget) {
  int expense = 1;
  int sum = 0;
  for(auto& x : seq) {
    if(sum + x <= optimand) {
      sum += x;
    }
    else{
      expense++;
      sum = x;
    }
  }
  return expense <= budget;
}
int BinSearch(vector<int>& a,int k) {
  int start = *min_element(a.begin(),a.end());
  int end = accumulate(a.begin(),a.end(),0LL);
  int ans = -1;

  while(start <= end) {
    int mid = start + (end - start) / 2;
    if(greedy(a,mid,k)){
      ans = mid;
      end = mid + 1;
    }
    else{
      start = mid + 1;
    }
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n , k;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  cout << BinSearch(a,k) << endl;
  return 0;
}