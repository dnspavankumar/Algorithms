/*
https://leetcode.com/problems/vowels-of-all-substrings/description/
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class Solution {
public:
  long long countVowels(string word) {
    int n = word.size();
    set<char> vowels = {'a','e','i','o','u'};
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
      if(vowels.find(word[i])!=vowels.end()) ans += (i+1)*(n-i); 
    }
    return ans;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  Solution sol;
  cout << sol.countVowels(s) << endl;
  return 0;
}