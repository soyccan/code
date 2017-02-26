// uva10870
// fast matrix exponentation
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,start,end) for (size_t i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
class Matrix {
protected:
    vector<vector<T>> _arr;
    size_t _rows, _cols;

public:
    template<typename U>
    friend Matrix<U> operator+(Matrix<U> x, const Matrix<U>& y);

    template<typename U>
    friend Matrix<U> operator-(Matrix<U> x, const Matrix<U>& y);

    template<typename U>
    friend Matrix<U> operator*(Matrix<U> x, U y);

    template<typename U>
    friend Matrix<U> operator/(Matrix<U> x, U y);

    template<typename U>
    friend ostream& operator<<(ostream& os, const Matrix<U>& x);

    template<typename U>
    friend Matrix<U> operator*(const Matrix<U>& x, const Matrix<U>& y);

    template<typename U>
    friend Matrix<U> operator^(const Matrix<U>& x, const Matrix<U>& y);

    template<typename U>
    friend Matrix<U> mul(const Matrix<U>& x, const Matrix<U>& y, U mod);

    template<typename U>
    friend Matrix<U> pow(const Matrix<U>& x, U e, U mod);

    Matrix(size_t rows=0, size_t cols=0) {
        this->_arr.resize(rows, vector<T>(cols));
        this->_rows = rows;
        this->_cols = cols;
    }
    vector<T>& operator[](size_t index) {
        return _arr[index];
    }
    Matrix& operator+=(const Matrix& x) {
        if (_rows != x._rows || _cols != x._cols)
            throw invalid_argument("matrix size not match");
        FOR(i, 0, this->_rows)
            FOR(j, 0, this->_cols)
                this->_arr[i][j] += x._arr[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& x) {
        if (_rows != x._rows || _cols != x._cols)
            throw invalid_argument("matrix size not match");
        FOR(i, 0, this->_rows)
            FOR(j, 0, this->_cols)
                this->_arr[i][j] -= x._arr[i][j];
        return *this;
    }
    Matrix& operator*=(T t) {
        FOR(i, 0, this->_rows)
            FOR(j, 0, this->_cols)
                this->_arr[i][j] *= t;
        return *this;
    }
    Matrix& operator/=(T t) {
        FOR(i, 0, this->_rows)
            FOR(j, 0, this->_cols)
                this->_arr[i][j] /= t;
        return *this;
    }
    Matrix& operator%=(T t) {
        // TODO: separate integral and float
        FOR(i, 0, this->_rows)
            FOR(j, 0, this->_cols)
                this->_arr[i][j] %= t;
        return *this;
    }
    static Matrix identity_matrix(size_t size) {
        Matrix x(size, size);
        FOR(i, 0, size) x._arr[i][i]=1;
        return x;
    }
    bool gaussian_elimination() {
        FOR(i, 0, this->_rows) {
            for (size_t j=i+1; j<this->_rows && this->_arr[i][i]==0; j++)
                swap(this->_arr[i], this->_arr[j]);
            if (this->_arr[i][i] == 0) return false;
            FOR(j, 0, this->_rows) {
                if (j != i) {
                    T t = this->_arr[j][i] / this->_arr[i][i];
                    FOR(k, 0, this->_cols) {
                        this->_arr[j][k] -= this->_arr[i][k] * t;
                    }
                }
            }
        }
        return true;
    }
    Matrix& transpose() {
        FOR(i, 0, this->_rows)
            FOR(j, i, this->_cols)
                swap(this->_arr[i][j], this->_arr[j][i]);
        return *this;
    }
};

template<typename T>
Matrix<T> operator+(Matrix<T> x, const Matrix<T>& y) { return x += y; }

template<typename T>
Matrix<T> operator-(Matrix<T> x, const Matrix<T>& y) { return x -= y; }

template<typename T>
Matrix<T> operator*(Matrix<T> x, T y) { return x *= y; }

template<typename T>
Matrix<T> operator/(Matrix<T> x, T y) { return x /= y; }

template<typename T>
Matrix<T> operator%(Matrix<T> x, T y) { return x %= y; } // TODO

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& x) {
    FOR(i, 0, x._rows) {
        FOR(j, 0, x._cols) {
            os << x._arr[i][j];
            if (j == x._cols-1)
                os << '\n';
            else
                os << ' ';
        }
    }
    return os;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& x, const Matrix<T>& y) {
    return mul(x, y);
}

template<typename T>
Matrix<T> operator^(const Matrix<T>& x, const Matrix<T>& y) {
    return pow(x, y);
}

template<typename T>
Matrix<T> mul(const Matrix<T>& x, const Matrix<T>& y, T mod=T()) {
    if (x._cols != y._rows)
        throw invalid_argument(
            "matrix size not suitable for multiplying\n"
            "it should be: (m*n) and (n*p) respectively\n"
            "try changing their order");
    Matrix<T> z(x._rows, y._cols);
    FOR(i, 0, x._rows)
        FOR(j, 0, y._cols)
            FOR(k, 0, x._cols) {
                z._arr[i][j] += x._arr[i][k] * y._arr[k][j];
                if (mod != T()) z._arr[i][j] %= mod;
            }
    return z;
}

// quick exponentation
template<typename T>
Matrix<T> pow(const Matrix<T>& x, T e, T mod=T()) {
    if (x._rows != x._cols)
        throw invalid_argument("matrix should be square");
    Matrix<T> y = x;
    Matrix<T> z = Matrix<T>::identity_matrix(x._rows);
    while (e > 0) {
        if (e % 2 == 1)
            z = mul(y, z, mod);
        y = mul(y, y, mod);
        e /= 2;
    }
    return z;
}

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,d,m;
    while (cin>>d>>n>>m && d && n && m) {
        Matrix<int> A(d,d), B(d,1);
        FOR(i,0,d) cin>>A[0][i];
        FOR(i,0,d-1) A[i+1][i]=1;
        for (int i=d-1; i>=0; i--) cin>>B[i][0];
        A%=m, B%=m;
        cout<<(mul(pow(A,n-1,m),B,m)[d-1][0]%=m)<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
