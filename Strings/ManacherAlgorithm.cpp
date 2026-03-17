#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> p;
string t;

// Manacher helper
vector<int> manacherHelper(string s) {
    int n = s.size();
    vector<int> p(n, 1);
    int left = 1, right = 1;

    for(int i = 1; i < n; i++){
        p[i] = max(0LL, min(right - i, p[left + right - i]));

        while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            p[i]++;

        if(i + p[i] > right){
            left = i - p[i];
            right = i + p[i];
        }
    }
    return p;
}

// Build transformed string
string build(string s) {
    string ans = "";
    for(char c : s) {
        ans += c;
        ans += '#';
    }
    return ans + '#';
}

// Preprocess
void preprocess(string s){
    t = build(s);
    p = manacherHelper(t);
}

// check if s[l...r] is palindrome
bool isPalindrome(int l, int r){
    int len = r - l + 1;

    // map to transformed string center
    int center = l + r;

    return p[center] > len;
}

// longest palindrome length
int longestPalindromeLength(string s){
    int ans = 0;
    for(int i = 0; i < p.size(); i++){
        ans = max(ans, p[i] - 1);
    }
    return ans;
}

// longest palindrome substring
string longestPalindrome(string s){
    int maxLen = 0, center = 0;

    for(int i = 0; i < p.size(); i++){
        if(p[i] - 1 > maxLen){
            maxLen = p[i] - 1;
            center = i;
        }
    }

    int start = (center - p[center] + 1) / 2;
    return s.substr(start, maxLen);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    preprocess(s);

    cout << "Longest Length: " << longestPalindromeLength(s) << endl;
    cout << "Longest Substring: " << longestPalindrome(s) << endl;

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r; // 0-based indexing

        if(isPalindrome(l, r)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}