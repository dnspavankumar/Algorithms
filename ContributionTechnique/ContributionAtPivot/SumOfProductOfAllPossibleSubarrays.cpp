#include<bits/stdc++.h>
using namespace std;


#define int long long
#define endl '\n'

int SumOfProductOfAllPossibleSubarrays(vector<int>& a) {
  int n = a.size();
  int ans = 0;
  int curr = 0;
  for(int i = 0 ; i < n ; i++) {
    curr = curr * a[i] + a[i];
    ans += curr;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& x : a) cin >> x;
  cout << SumOfProductOfAllPossibleSubarrays(a) << endl;
  return 0;
}

/*
The contributor element is the current element 

To find its contribution We need to observe how many subarrays end with that particular element

This is known as ending contribution

And the contribution transition will be

This way

the current element can be taken alone or can contribute to all other previously formed subarrays

Hence the current element can be contributing this way {current element} + {previous all subarrays ({s1}{s2}....)u (cur)}

therefore curr + prev*curr; is the contribution of curr element and this should be added to the final answer

*/