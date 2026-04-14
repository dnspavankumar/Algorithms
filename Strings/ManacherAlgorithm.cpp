#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> p;
string t;

// Build transformed string: "#a#b#c#"
string build(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}

// Manacher algorithm
vector<int> manacherHelper(const string &s) {
    int n = s.size();
    vector<int> p(n, 0);

    int center = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (i < right)
            p[i] = min(right - i, p[2 * center - i]);

        // expand around center i
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
               s[i - p[i] - 1] == s[i + p[i] + 1]) {
            p[i]++;
        }

        // update center and right boundary
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    return p;
}

// Preprocess
void preprocess(const string &s) {
    t = build(s);
    p = manacherHelper(t);
}

// Check if s[l...r] is palindrome (0-based)
bool isPalindrome(int l, int r) {
    int len = r - l + 1;

    // correct mapping to transformed string
    int center = l + r + 1;

    return p[center] >= len;
}

// Longest palindrome length
int longestPalindromeLength() {
    int ans = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        ans = max(ans, p[i]);
    }
    return ans;
}

// Longest palindrome substring
string longestPalindrome(const string &s) {
    int maxLen = 0, center = 0;

    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            center = i;
        }
    }

    int start = (center - maxLen) / 2;
    return s.substr(start, maxLen);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    preprocess(s);

    cout << "Longest Length: " << longestPalindromeLength() << endl;
    cout << "Longest Substring: " << longestPalindrome(s) << endl;

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r; // 0-based

        if (isPalindrome(l, r)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
