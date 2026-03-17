/*
Problem Link :
https://leetcode.com/problems/edit-distance/description/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 Recursive (corrected)
    int rec(string &s, string &t, int n, int m){
        if(n == 0) return m;
        if(m == 0) return n;

        if(s[n-1] == t[m-1]){
            return rec(s, t, n-1, m-1);
        }
        else{
            return 1 + min({
                rec(s, t, n-1, m),     // delete
                rec(s, t, n, m-1),     // insert
                rec(s, t, n-1, m-1)    // replace
            });
        }
    }

    // 🔹 Memoization
    int memoHelper(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n == 0) return m;
        if(m == 0) return n;

        if(dp[n][m] != -1) return dp[n][m];

        if(s[n-1] == t[m-1]){
            return dp[n][m] = memoHelper(s, t, n-1, m-1, dp);
        }
        else{
            return dp[n][m] = 1 + min({
                memoHelper(s, t, n-1, m, dp),     // delete
                memoHelper(s, t, n, m-1, dp),     // insert
                memoHelper(s, t, n-1, m-1, dp)    // replace
            });
        }
    }

    int rec(string s, string t){
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memoHelper(s, t, n, m, dp);
    }

    // 🔹 Tabulation (Optimal DP)
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base cases
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // delete
                        dp[i][j-1],     // insert
                        dp[i-1][j-1]    // replace
                    });
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solution;
    string s, t;
    cin >> s >> t;

    cout << solution.minDistance(s, t);

    return 0;
}