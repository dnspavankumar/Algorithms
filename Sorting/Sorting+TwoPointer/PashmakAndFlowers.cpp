
/*

https://codeforces.com/problemset/problem/459/B

*/

/*

The question asks us to pick one min and one max at a time so that the max difference increases
As we know when all numbers are positive the max difference can be obtained by picking the maximum and the minimum
Hence we use sorting + two pointers because after sorting it gets easier to pick the max and min
This is the basic idea of two pointers where you pick two pairs which are designed such a way that they take closer to a solution

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long  
#define endl '\n'

void MaxDifference(vector<int>& a) {
    int n = a.size();
    sort(a.begin(), a.end());

    int mxdiff = a[n - 1] - a[0];

    // Handle the edge case where all flowers are the same
    if (mxdiff == 0) {
        int ways = n * (n - 1) / 2;
        cout << mxdiff << " " << ways << endl;
        return;
    }

    int left = 0;
    int right = n - 1;
    int minimumCount = 0;
    int maximumCount = 0;

    int minVal = a[0];
    int maxVal = a[n - 1];

    // Corrected loop logic: compare array values, not indices
    while (left < n && a[left] == minVal) {
        minimumCount++;
        left++;
    }
    while (right >= 0 && a[right] == maxVal) {
        maximumCount++;
        right--;
    }

    // Multiply the counts of min and max values
    cout << mxdiff << " " << minimumCount * maximumCount << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    MaxDifference(a);

    return 0;
}