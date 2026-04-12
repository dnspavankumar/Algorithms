#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
int maxHappiness(vector<int>& a,vector<int>& b,vector<int>& c,int n) {
            vector<vector<int>> dp(n,vector<int> (3));
            dp[0][0] = a[0];
            dp[0][1] = b[0];
            dp[0][2] = c[0];
            for(int i = 1 ; i < n ; i++) {
                dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i];
                dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b[i];
                dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c[i];  
            }
            return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
        }

*/
class Solution {
    public:
        // divide and conquer
        int maxHappiness(vector<int>& a,vector<int>& b,vector<int>& c,int n) {
            vector<int> prev(3);
            vector<int> cur(3);
            prev[0] = a[0];
            prev[1] = b[0];
            prev[2] = c[0];
            for(int i = 1 ; i < n ; i++) {
                cur[0] = max(prev[1],prev[2]) + a[i];
                cur[1] = max(prev[0],prev[2]) + b[i];
                cur[2] = max(prev[0],prev[1]) + c[i];
                prev = cur;
            }
            return max({prev[0],prev[1],prev[2]});
        }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i] >> c[i];
    Solution sol;
    cout << sol.maxHappiness(a,b,c,n) << endl;
    return 0;
}