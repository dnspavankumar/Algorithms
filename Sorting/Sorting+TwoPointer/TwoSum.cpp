#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool TwoSum(vector<int>& a,int target) {
    int n = a.size();
    int left = 0;
    int right = 0;
    while(left < right) {
        int sum = a[left] + a[right];
        if(sum==target) return true;
        else if(sum < target) left++;
        else right--;     
    }
    return false;
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

    cout << TwoSum(a,target) << endl;

    return 0;
}