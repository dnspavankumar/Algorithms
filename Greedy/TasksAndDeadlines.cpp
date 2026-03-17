/*
Problem Link:
https://cses.fi/problemset/task/1630

*/

#include <bits/stdc++.h>
using namespace std;

struct Task {
    long long S, D, T;
};

int main() {
    int n;
    cin >> n;

    vector<Task> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].S >> a[i].D >> a[i].T;
    }

    // Sort by T_i / D_i
    sort(a.begin(), a.end(), [](Task &x, Task &y) {
        return x.T * y.D < y.T * x.D;
    });

    long long time = 0;
    long long totalScore = 0;

    for (auto &task : a) {
        time += task.T;
        totalScore += task.S - task.D * time;
    }

    cout << totalScore << endl;
}