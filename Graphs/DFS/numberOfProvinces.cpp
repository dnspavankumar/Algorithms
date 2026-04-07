#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void dfs(int start,vector<vector<int>>& adj,vector<bool>& visited) {
    visited[start] = true;
    for(auto& nbr : adj[start]) {
        if(!visited[nbr]) {
            dfs(start,adj,visited);
        }
    }
}
int numberOfProvinces(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n,false);
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            count++;
            dfs(i,adj,visited);
        }
    }
    return count;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < n ; i++) {
        int u;
        cin >> u;
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << numberOfProvinces(adj) << endl;
    return 0;
}