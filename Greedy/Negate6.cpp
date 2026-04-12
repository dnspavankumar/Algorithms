/*
https://codeforces.com/problemset/problem/2218/B
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int sum = 0;
    vector<int> a(7);
    for(auto& x : a) cin >> x;
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 0 ; i < 6 ; i++) ans -= a[i];
    ans += a[6];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}