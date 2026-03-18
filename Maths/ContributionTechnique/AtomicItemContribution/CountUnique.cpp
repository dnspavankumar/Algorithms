/*
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class Solution {
public:
  int uniqueLetterString(string s) {
    int n = s.size();
    vector<int> lastOccurence(26,-1);
    vector<int> secondLastOccurence(26,-1);
    long long ans = 0;
    for(int i = 0 ; i < n ; i++) {
      int c = s[i] - 'a';
      if(lastOccurence[c]!=-1) ans += (long long)(lastOccurence[c] - secondLastOccurence[c]) * (i - lastOccurence[c]);
      secondLastOccurence[c] = lastOccurence[c];
      lastOccurence[c] = i;
    }    
    for(int i = 0  ; i < 26 ; i++){
      if(lastOccurence[i]!=-1) ans+= (long long) (lastOccurence[i]-secondLastOccurence[i]) * (n-lastOccurence[i]);
    }
    return ans;
  } 
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  Solution sol;
  while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << sol.uniqueLetterString(s) << endl;
  }
  return 0;
}