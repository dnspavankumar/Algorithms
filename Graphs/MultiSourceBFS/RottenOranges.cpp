#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> grid[i][j] ;
        }
    }
    cout << rottenOranges(grid) << endl;
    return 0;
}