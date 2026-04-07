#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    // Check upper-left diagonal
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') return false;
        i--; j--;
    }
    // Check upper-right diagonal
    i = row - 1, j = col + 1;
    while (i >= 0 && j < n) {
        if (board[i][j] == 'Q') return false;
        i--; j++;
    }
    return true;
}

void solve(int n, int row, vector<vector<string>> &ans, vector<string> &board) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(n, row + 1, ans, board);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(n, 0, ans, board);
    return ans;
}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    int n;
    cin >> n;
    vector<vector<string>> ans =  sol.solveNQueens(n);
    for(int i = 0 ; i < ans.size() ; i++) {
        for(int j = 0 ; j < ans[0].size() ; j++) {
            cout << ans[i][j] << endl;
        }
        cout << "-----------------" << endl;
        cout << endl;
    }
    return 0;
}