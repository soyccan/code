// Yazmau
#include<bits/stdc++.h>
using namespace std;
map<double,int> cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a = 0  , b = 0;
    for(int h=0;h<=23;h++)
        for(int m=0;m<=59;m++,a+=0.5,b+=6) {
            if(a>=360)   a -= 360;
            if(b>=360)   b -= 360;
            double dif = fabs(a-b);
            cnt[min(dif,360.0-dif)]++;
        }
    double x;
    while(cin >> x)
        cout << cnt[min(x,360.0-x)] << endl;
    return 0;
}
