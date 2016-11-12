#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e10;
string conv(int x) {
    string s;
    while (x) {
        s.push_back('0'+x%2);
        x/=2;
    }
    reverse(s.begin(), s.end());
    return s;
}
string conv(double x) {
    string s;
    while (x>EPS) {
        x*=2;
        s.push_back('0'+int(x));
        x-=int(x);
    }
    return s;
}
string tos(vector<int> v,int l,int r) {
    string s;
    for (int i=l; i<=r; i++)
        s.push_back('0'+v[i]);
    return s;
}
string period(int x) {
    // 1/x
    // terminating
    int y=x;
    while (y%2==0) y/=2;
    while (y%5==0) y/=5;
    if (y==1) return "0";

    // repeating
    vector<int> v;
    int last[20];
    memset(last,-1,sizeof last);
    int t=10;
    for (int i=0; i<1000; i++) {
        v.push_back(t/x);
        // cout<<v.back()<<endl;
        t=t%x*10;
        if (last[i])
        // for (int j=i-1; j>=1; j--) {
        //     // cout<<"  "<<v[i+1]<<' '<<v[j+1]<<'\n';
        //     if (v[i]==v[j] && v[i-1]==v[j-1])
        //         return tos(v,j+1,i);
        // }
    }
    return "-";
}
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    double n;
    while (cin>>n) {
        // conv(int(n));
        // conv(n-int(n));
        cout<<period(n)<<'\n';
    }
    return 0;
}
