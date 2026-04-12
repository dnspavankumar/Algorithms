#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class Solution {
    public:
    // int rec(string s, string t, int n, int m) {
    //     if(n==0 || m==0) return 0;
    //     if(s[n-1]==t[m-1]) {
    //         return rec(s,t,n-1,m-1);
    //     } 
    //     else{
    //         return max(rec(s,t,n-1,m),rec(s,t,n,m-1));
    //     }
    // }
    string lcs(string s,string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = 0;
        }
        for(int j = 0 ; j <= m ; j++) {
            dp[0][j] = 0;
        }
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(s[i-1]==t[j-1]) dp[i][j] = (dp[i-1][j-1] + 1);
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // length of the longest common subsequence
        int len = dp[n][m];

        int i = n;
        int j = m;
        string ans = "";
        while(i>0 && j>0) {
            if(s[i-1]==t[j-1]){
                ans += s[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string t;
    cin >> t;
    Solution sol;
    cout << sol.lcs(s,t) << endl;
    return 0;
}