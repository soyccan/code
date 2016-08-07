#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w;
    while (cin>>h>>w && h && w) {
        double res = log(w)/log(h);
        double l=1, r=1e10, N=(l+r)/2;
        for (int i=0; i<100; i++) {
            N = (l+r)/2;
            double v = log(N)/log(N+1);
            if (abs(v - res) < 1e-10) break;
            else if (v < res) l = N;
            else if (v > res) r = N;
        }

        int k=0;
        while (h*pow(N+1, -k) > 1-1e-5) k++;
        k--;
        cout<<fixed<<setprecision(0)
            <<(pow(N,k)-1) / (N-1)
            <<' '
            <<h * (pow(N/(N+1), k+1)-1) / (-1/(N+1)) <<'\n';
    }
    return 0;
}

