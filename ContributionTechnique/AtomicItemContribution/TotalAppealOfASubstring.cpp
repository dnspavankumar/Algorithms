/*
https://leetcode.com/problems/total-appeal-of-a-string/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long appealSum(string s) {
    int n = s.size();
    vector<int> lastOccurence(26,-1);
    long long ans = 0 ;
    for(int i = 0 ; i < n ; i++) {
      ans += (long long)(i-lastOccurence[s[i]-'a']) * (n-i);
      lastOccurence[s[i]-'a'] = i;
    }
    return ans;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  string s;
  cin >> s;
  cout << sol.appealSum(s) <<endl;
  return 0;
}
