// uva10093
// math, base
#include <bits/stdc++.h>
using namespace std;
inline int num(char c) {
    if (isdigit(c)) return c-'0';
    else if (isupper(c)) return 10+c-'A';
    else if (islower(c)) return 36+c-'a';
    else return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin>>s) {
        int base=2, sum=0;
        for (char c : s) {
            base = max(base, num(c)+1);
            sum += num(c);
        }
        int ans = -1;
        for (; base<=sum+1; base++) {
            // cout<<"sum:"<<sum<<" base:"<<base<<endl;
            if (sum % (base-1) == 0) {
                ans = base;
                break;
            }
        }
        if (sum == 0) cout<<"2\n";
        else if (ans == -1 || ans > 62) cout<<"such number is impossible!\n";
        else cout<<ans<<'\n';
    }
    return 0;
}
