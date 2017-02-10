#include <cassert>
#include <complex>
#include <vector>
using std::complex;
using std::vector;
// using std::assert;

inline complex<double> omega(int n, int k) {
    // ω = e ^ 2πki/n
    return exp(complex<double>(0, 2.*acos(-1.)*k/n));
}
vector<complex<double>> fft(const vector<complex<double>>& polynomial) {
    int n = polynomial.size();
    if (n == 1) return vector<complex<double>>{omega(n, 1)};

    assert((n & (n-1)) == 0); // n must be power of 2

    vector<complex<double>> even, odd;
    for (int i=0; i<n; i++) {
        if (i % 2 == 0)
            even.push_back(polynomial[i]);
        else
            odd.push_back(polynomial[i]);
    }

    vector<complex<double>> even_val(fft(even));
    vector<complex<double>> odd_val(fft(odd));
    vector<complex<double>> val(n);

    // calc f(ω_n^k)
    for (int k=0; k<n; k++) {
        val[k] = even_val[k%(n/2)] + omega(n, k) * odd_val[k%(n/2)];
    }
    return val;
}
