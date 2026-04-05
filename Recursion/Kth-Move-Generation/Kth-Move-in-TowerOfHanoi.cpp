/*Find the Kth move in Tower Of Hanoi*/


/*
No need to explore all branches if K is in the first branch go for it
other wise if its the mid move go for it
else go for the right subtree 
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void kthMove(int s, int d, int a, int n, int k) {
    if(n == 0) return;

    int mid = (1 << (n-1)) - 1;

    if(k < mid) {
        kthMove(s, a, d, n-1, k);
    }
    else if(k == mid) {
        cout << s << " " << d << endl;
    }
    else {
        kthMove(a, d, s, n-1, k - (mid + 1));
    }
}
void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << (1,2,3,n,k) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}