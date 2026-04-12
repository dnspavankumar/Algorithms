#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class Solution {
    public:
    int maxSum(int n,vector<int>& w,vector<int>& v,int c) {
        vector<vector<int>> dp(n+1,vector<int>(c+1));
        // if capacity is 0
        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = 0;
        }
        // if capacity is whatever but there are no items
        for(int i = 0 ; i <= c ; i++) {
            dp[0][c] = 0;
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= c ; j++) {
                int pick = 0;
                if(j>=w[i-1])
                    pick = dp[i-1][j-w[i-1]] + v[i-1];
                int drop = dp[i-1][j];
                dp[i][j] = max(pick,drop);
            }
        }
        return dp[n][c];
    }
    int maxSum1(int n,vector<int>& w,vector<int>& v,int c) {
        vector<int> prev(c+1);
        vector<int> cur(c+1);
        prev[0] = 0;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= c ; j++) {
                int pick = 0;
                if(j >= w[i-1]) pick = prev[j-w[i-1]] + v[i-1];
                int drop = prev[j];
                cur[j] = max(pick,drop);
            }
            prev = cur;
        }
        return prev[c];
    }
    int maxSum2(int n,vector<int>& w,vector<int>& v,int c) {
        vector<int> dp(c+1,0);
        for(int i = 0 ; i < n ; i++) {
            for(int j = c ; j >= w[i] ; j--) {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        return dp[c];
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int W;
    cin >> W;
    vector<int> w(N);
    vector<int> v(N);
    for(int i = 0 ; i < N ; i++) {
        cin >> w[i] >> v[i];
    }
    Solution sol;
    cout << sol.maxSum2(N,w,v,W) << endl;
    return 0;
}