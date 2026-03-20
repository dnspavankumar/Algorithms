#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

#define lb lower_bound
#define ub upper_bound

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    unordered_map<int,int> positions;
    for(int i = 0; i < n; i++) positions[a[i]] = i;

    set<int> seen;
    seen.insert(-1);
    seen.insert(-2);
    seen.insert(n);
    seen.insert(n+1);

    int sum = 0;

    for(int i = n; i >= 1; i--) {
        int k = positions[i];

        auto it = seen.lb(k);
        int r1 = *it;
        it++;
        int r2 = *it;

        it = seen.lb(k);
        it--;
        int l1 = *it;
        it--;
        int l2 = *it;

        if(l1 != -1) {
            sum += i * (l1 - l2) * (r1 - k);
        }

        if(r1 != n) {
            sum += i * (k - l1) * (r2 - r1);
        }

        seen.insert(k);
    }

    cout << sum << endl;
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