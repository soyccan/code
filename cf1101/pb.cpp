#include <bits/stdc++.h>
#define FOR(i,a,n) for (int i=a; i<n; i++)
using namespace std;

int A[500010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    cin >> t;
    while (cin >> s) {
        vector<char> ans;
        bool op = false;
        for (char c : s) {
            if (c == '[' && ans.empty()) {
                ans.push_back(c);
            }
            else if (c == ':' && !ans.empty() && ans.back() == '[') {
                ans.push_back(c);
                op = true;
            }
            else if (c == '|' && !ans.empty() && ans.back() == ':' && op) {
                ans.push_back(c);
            }
            else if (c == ':' && !ans.empty() && ans.back() == '|' && op) {
                ans.push_back(c);
                op = false;
            }
            else if (c == ']' && !ans.empty() && ans.back() == ':' && !op) {
                ans.push_back(c);
            }
        }
        if (ans.empty())
            cout << "-1\n";
        else
            cout << ans.size() << '\n';
    }
    return 0;
}
