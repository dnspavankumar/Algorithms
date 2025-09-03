#include<bits/stdc++.h>
using namespace std;
bool isValid(long long x,long long y,long long n){
    return x>=0 && x<n && y>=0 && y<n;
}
bool isPossible(vector<string>& board,long long x,long long y,long long n){
    vector<vector<int>>directions={
        {2,-1},{2,1},{-2,-1},{-2,1},{-1,2},{-1,-2},{1,2},{1,-2}
    };
    for(auto& direction:directions){
        int dx = direction[0];
        int dy = direction[1];
        if(isValid(x+dx,y+dy,n))
        if(board[x+dx][y+dy]=='K')return false;
    }
    return true;
}
void helper(vector<string>& board,long long row,long long col,long long& count,long long n){
    if(row==n){
        count++;
        return;
    }
    for(int col=0;col<n;col++){
        if(isPossible(board,row,col,n)){
            board[row][col]='K';
            helper(board,row+1,col,count,n);
        }
        board[row][col]='.';
    }
}
long long solve(long long n){
    long long row = 0;
    long long col = 0;
    vector<string>board(n,string(n,'.'));
    long long count=0;
    helper(board,row,col,count,n);
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cout<<solve(i)<<endl;
    }
    return 0;
}
