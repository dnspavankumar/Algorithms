#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int CountPairs(vector<int>& a,int target) {
  int n = a.size();
  int cnt = 0;
  map<int,int> f;
  for(auto& x : a) {
    cnt += f[target - x];
    f[x]++;
  }
  return cnt;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  int target;
  cin >> target;
  cout << CountPairs(a,target) << endl;
  return 0;
}

/*
Intuition :
The contribution technique at pivot basically asks u to pick a pivot and based on that pivot you compute the contribution
now I am checking does my current index i on which I am at present is contributing to the target sum


hence the current element x is the contributor and the target sum is what x is contributing to

Now to check if x is actually contributing to the target sum I need to check is x present with a valid element to pair

so that their sum is equals to the target
*/