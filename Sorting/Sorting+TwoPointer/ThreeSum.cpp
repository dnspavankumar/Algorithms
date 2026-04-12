#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> threeSum(vector<int>& a,int target) {
    int n = a.size();
    sort(a.begin(),a.end());
    for(int i = 0 ; i < n ; i++) {
        int left = i+1;
        int right = n-1;
        while(left < right) {
            if((a[i]+a[left]+a[right])==target) return {i,left,right};
        }
    }
    return {-1};
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    vector<int> ans = threeSum(a,target);
    for(auto& x : a) cout << x << " ";
    return 0;
}