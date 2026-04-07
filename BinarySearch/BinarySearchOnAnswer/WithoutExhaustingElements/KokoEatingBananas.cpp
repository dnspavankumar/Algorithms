#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool greedy(int optimand,vector<int>& piles,int budget) {
    int expense = 0; 
    for(auto& pile : piles) {
        expense += ((pile + optimand - 1)/optimand);
        if(expense > budget) return false;
    }
    return true;
}
class Solution {
public:
    int minSpeed(vector<int>& piles, int h) {
        int start = *max_element(piles.begin(),piles.end());
        int end = accumulate(piles.begin(),piles.end(),0LL);
        int ans = -1;
        while(start<=end) {
            int mid = start + (end-start) / 2;
            if(greedy(mid,piles,h)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    int n;
    cin >> n;
    int h;
    cin >> h;
    vector<int> piles(n);
    for(auto& pile : piles) cin >> pile;
    int k = sol.minSpeed(piles,h);
    cout << k << endl;
    return 0;
}