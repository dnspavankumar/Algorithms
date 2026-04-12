#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n';

bool isOpeningBrace(char c) {
    return (c=='(' || c=='{' || c=='[');
}

bool match(char c) {
    if(c==')') return '(';
    else if(c=='}') return '{';
    else if(c==']') return '[';
}
void solve() {
    string s;
    cin >> s;
    stack<int> st;
    for(int i = 0 ; i < s.size() ; i++) {
        if(isOpeningBrace(s[i])) st.push(s[i]);
        else{
            if(!st.empty()){
                if(st.top()==match(s[i])) {
                    st.pop();
                }   
            }
            else {
                cout << "No" << endl;
                return;
            }
        }
    }
}

signed main() {
    ios:sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}