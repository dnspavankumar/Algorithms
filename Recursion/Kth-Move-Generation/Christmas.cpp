/*
https://atcoder.jp/contests/abc115/tasks/abc115_d
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int len[55] , pat[55];

int rec(int n,int x) {
    if(n==0) {
        if(x>0) return 1;
        else return 0;
    }
    if(x==1) return 0;
    else if(x <= len[n-1]+1) return rec(n-1,x-1);
    else if(x == 2 + len[n-1]) return pat[n-1] + 1;
    else if(x <= 2*(len[n-1]+1)) return pat[n-1]+1+rec(n-1,x-(2+len[n-1]));
    else return pat[n];
}
void solve() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    len[0] = 1;
    pat[0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        len[i] = 2*len[i-1] + 3;
        pat[i] = 2*pat[i-1] + 1;
    }
    cout << rec(n,x) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}