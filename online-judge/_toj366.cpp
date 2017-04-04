#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6;
vector<int> primes;
bool prm[MAXN+5];
int af[MAXN+5],bf[MAXN+5];
void factorize(int num,int arr[]) {
    memset(arr,0,sizeof(int)*(MAXN+5));
    for (int i=0; i<primes.size(); i++) {
        for (int j=primes[i]; j<=num; j*=primes[i])
            arr[primes[i]]+=num/j;
    }
}
void fact(int num,int arr[]) {
    memset(arr,0,sizeof(int)*(MAXN+5));
    for (int i=0; i<primes.size(); i++) {
        while (num && num%primes[i]==0) {
            num/=primes[i];
            arr[primes[i]]++;
        }
    }
}
void getprimes() {
    memset(prm,1,sizeof prm);
    for (int i=2; i<=MAXN; i++) {
        if (prm[i]) {
            primes.push_back(i);
            for (int j=i+i; j<=MAXN; j+=i)
                prm[j]=0;
        }
    }
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    getprimes();
    int a,b;
    while (cin>>a>>b) {
        factorize(a,af);
        factorize(b,bf);
        int ra=1, rb=1;
        for (int i=2; i<=MAXN; i++) {
            if (af[i]>bf[i]) {
                ra*=pow(i,af[i]-bf[i]);
                af[i]=bf[i];
            } else {
                rb*=pow(i,bf[i]-af[i]);
            }
        }
        fact(ra+rb,bf);
        int ans=0;
        for (int i=2; i<=MAXN; i++)
            if (af[i]||bf[i])
                ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
