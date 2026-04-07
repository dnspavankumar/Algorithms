#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int LongestCommonSubsequence(string& s,string& t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    //If there are no free characters in one of the strings the longest common subsequence is empty
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
    for(int j = 0 ; j <= m ; j++) dp[0][j] = 0;

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            if(s[i-1]==t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string t;
    cin >> t;
    cout << LongestCommonSubsequence(s,t) << endl;
    return 0;
}