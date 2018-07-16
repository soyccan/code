#include <bits/stdc++.h>
// #define int long long
#define double long double
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct FFT {
    inline static complex<double> omega(int n, int k) {
        // ω = e ^ 2πki/n
        return exp(complex<double>(0, 2.*acos(-1.)*k/n));
    }
    static vector<complex<double>>
    fast_fourier_transform(const vector<complex<double>>& polynomial) {
        size_t n = polynomial.size();
        if ((n & (n-1)) != 0)
            throw invalid_argument("polynomial's length must be power of 2");
        if (n == 1)
            return vector<complex<double>> { polynomial[0] };

        vector<complex<double>> even, odd;
        for (size_t i=0; i<n; i++) {
            if (i % 2 == 0)
                even.push_back(polynomial[i]);
            else
                odd.push_back(polynomial[i]);
        }

        vector<complex<double>> even_val(fast_fourier_transform(even));
        vector<complex<double>> odd_val(fast_fourier_transform(odd));
        vector<complex<double>> val(n);

        // calc val[k] = f(ω_n^k)
        for (size_t k=0; k<n; k++)
            val[k] = even_val[k%(n/2)] + omega(n, k) * odd_val[k%(n/2)];
        return val;
    }
    static vector<complex<double>>
    inverse_fast_fourier_transform(const vector<complex<double>>& polynomial) {
        vector<complex<double>> val(fast_fourier_transform(polynomial));
        reverse(val.begin()+1, val.end());
        for (size_t i=0; i<polynomial.size(); i++)
            val[i] /= (double)polynomial.size();
        return val;
    }
};

vector<complex<double>> bignum(const string& x,int n) {
    vector<complex<double>> v(n);
    for (int i=0; i<x.size(); ++i) {
        v[i].real(x[x.size()-1-i]-'0');
    }
    return FFT::fast_fourier_transform(v);
}
vector<int> mul(vector<int>& a,vector<int>& b) {
    int n=1<<17;
    vector<complex<double>> x=bignum(a,n);
    vector<complex<double>> y=bignum(b,n);
    FOR(i,n) x[i]*=y[i];
    vector<complex<double>> z=FFT::inverse_fast_fourier_transform(x);
    vector<int> ans(z.size());
    FOR(i,z.size()) {
        ans[i]+=round(z[i].real());
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while (ans.size()>1 && !ans.back()) ans.pop_back();
    return ans;
}
vector<int> qpow(vector<int>& x,int y) {
    // vector<int>
}
string tostring(vector<int>& x) {
    string s;
    FOR(i,x.size()) s.push_back('0'+x[i]);
    reverse(s.begin(), s.end());
    return s;
}
istream& operator>>(istream& is,vector<int>& x) {
    string s;
    is>>s;
    for (int i=s.size()-1; i>=0; i--) x.push_back(s[i]);
    return is;
}
ostream& operator<<(ostream& os,vector<int>& x) {
    for (int i=x.size()-1; i>=0; i--) os<<x[i];
    cout<<'\n';
    return os;
}
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    string a,b,c;
    while (cin>>c>>a>>b) {
        if (c=="mul") {
            cout<<mul(a,b)<<'\n';
        } else {
            cout<<qpow(a,b)<<'\n';
        }
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
