#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

/*
candidate transitions : i+1, i+2 , i+3 ... i+k
*/
int minCost(vector<int>& h,int n,int k) {
    vector<int> dp(n,LLONG_MAX);
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    for(int i = 2 ; i < n ; i++) {
        for(int candidate = 1 ; candidate <= k ; candidate++) {
            if(i >= candidate)
                dp[i] = min(dp[i],dp[i-candidate] + abs(h[i-candidate]-h[i]));
        }
    }
    return dp[n-1];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> h(n);
    for(auto& x : h) cin >> x;
    cout << minCost(h,n,k) << endl;
    return 0;
}