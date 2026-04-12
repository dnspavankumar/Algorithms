#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

/*
state : the current configuration (i)
candidate transitions : (i+1) (i+2)
transition : picking optimal candidate
solution space (0,n-1) => n;
*/

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto& x : h) cin >> x;

    vector<int> dp(n);
    // state : dp[k] the min cost to reach kth stone
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    // transitions
    for(int i = 2 ; i < n ; i++) {
        // candidate transitions
        int candidate1 = dp[i-1] + abs(h[i-1]-h[i]);
        int candidate2 = dp[i-2] + abs(h[i-2]-h[i]);
        // transition
        dp[i] = min(candidate1, candidate2);
    }
    cout << dp[n-1] << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}