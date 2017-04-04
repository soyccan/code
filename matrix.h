// TODO: inverse matrix and augmented matrix
#ifndef _MATRIX_H
#define _MATRIX_H
#define FOR(i,start,end) for (size_t i=start; i<end; ++i)

#include <vector>
using std::vector;

#include <stdexcept>
using std::length_error;
using std::invalid_argument;

#include <limits>
using std::numeric_limits;

#include <ostream>
using std::ostream;

#include <cstddef>
using std::size_t;

#include <cstring>
using std::memset;

#include <algorithm>
using std::swap;

#include <type_traits>
using std::is_integral;

template<typename T>
class Matrix {
public:
    Matrix(size_t rows=0, size_t cols=0) {
        _arr.resize(rows, vector<T>(cols));
        _rows = rows;
        _cols = cols;
    }
    vector<T>& operator[](size_t index) {
        return _arr[index];
    }
    Matrix& operator+=(const Matrix& x) {
        if (_rows != x._rows || _cols != x._cols)
            throw invalid_argument("matrix size not match");
        FOR(i, 0, _rows)
            FOR(j, 0, _cols)
                _arr[i][j] += x._arr[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& x) {
        return *this += -x;
    }
    Matrix& operator*=(T t) {
        FOR(i, 0, _rows)
            FOR(j, 0, _cols)
                _arr[i][j] *= t;
        return *this;
    }
    Matrix& operator/=(T t) {
        FOR(i, 0, _rows)
            FOR(j, 0, _cols)
                _arr[i][j] /= t;
        return *this;
    }
    Matrix& operator%=(T t) {
        FOR(i, 0, _rows)
            FOR(j, 0, _cols)
                _arr[i][j] %= t;
        return *this;
    }
    int gaussian_elimination() {
        // TODO: augumented matrix
        bool sign = 0; // whether determinant should change sign
        FOR(i, 0, _rows) {
            for (size_t j=i+1; j<_rows && _arr[i][i]==0; j++) {
                swap(_arr[i], _arr[j]);
                sign = !sign;
            }
            if (_arr[i][i] == 0)
                // fail
                return -1;
            FOR(j, 0, _rows) {
                if (j != i) {
                    T t = _arr[j][i] / _arr[i][i];
                    FOR(k, 0, _cols) {
                        _arr[j][k] -= _arr[i][k] * t;
                    }
                }
            }
        }
        return sign;
    }
    Matrix& transpose() {
        FOR(i, 0, _rows)
            FOR(j, i, _cols)
                swap(_arr[i][j], _arr[j][i]);
        return *this;
    }
    T determinant() const {
        if (_rows != _cols)
            throw invalid_argument("matrix should be square");
        Matrix x = *this;
        int sign = x.gaussian_elimination();
        T res = 1;
        FOR(i, 0, x._rows) res *= x._arr[i][i];
        if (sign == 1) return -res;
        else if (sign == 0) return res;
        else return 0;
    }
    friend Matrix operator-(Matrix x) { return x *= -1; }
    friend Matrix operator+(Matrix x, const Matrix& y) { return x += y; }
    friend Matrix operator-(Matrix x, const Matrix& y) { return x -= y; }
    friend Matrix operator*(Matrix x, T y) { return x *= y; }
    friend Matrix operator/(Matrix x, T y) { return x /= y; }
    friend Matrix operator%(Matrix x, T y) { return x %= y; }
    friend ostream& operator<<(ostream& os, const Matrix& x) {
        FOR(i, 0, x._rows) {
            FOR(j, 0, x._cols) {
                os << x._arr[i][j];
                if (j == x._cols-1)
                    os << '\n';
                else
                    os << ',' << ' ';
            }
        }
        return os;
    }
    friend Matrix operator*(const Matrix& x, const Matrix& y) {
        return mul(x, y);
    }
    template<typename Int>
    friend Matrix operator^(const Matrix& x, Int y) {
        return pow(x, y);
    }
    template<typename Int=int>
    static Matrix mul(const Matrix& x, const Matrix& y, Int mod=Int()) {
        // modulo acts only when T == Int
        static_assert(is_integral<Int>::value, "modulo not integral");
        if (x._cols != y._rows)
            throw invalid_argument(
                "matrix size not suitable for multiplying\n"
                "it should be: (m*n) and (n*p) respectively\n"
                "try changing their order");
        Matrix z(x._rows, y._cols);
        FOR(i, 0, x._rows)
            FOR(j, 0, y._cols)
                FOR(k, 0, x._cols) {
                    z._arr[i][j] += x._arr[i][k] * y._arr[k][j];
                    if (mod != Int())
                        // the same as: z._arr[i][j] %= mod
                        // handle floating types, which cannot do modulo
                        _mod_assign(z._arr[i][j], mod);
                }
        return z;
    }
    template<typename Int>
    static Matrix pow(Matrix x, Int y, Int mod=Int()) {
        // quick exponentation
        static_assert(is_integral<Int>::value, "modulo or exponent not integral");
        if (x._rows != x._cols)
            throw invalid_argument("matrix should be square");
        Matrix z = Matrix::identity_matrix(x._rows);
        while (y > 0) {
            if (y % 2 == 1)
                z = mul(x, z, mod);
            x = mul(x, x, mod);
            y /= 2;
        }
        return z;
    }
    static Matrix identity_matrix(size_t size) {
        Matrix x(size, size);
        FOR(i, 0, size) x._arr[i][i]=1;
        return x;
    }

protected:
    vector<vector<T>> _arr;
    size_t _rows, _cols;

private:
    // prevent something like (double) %= (int)
    template<typename T1, typename T2>
    static T1& _mod_assign(T1& x, T2 mod) { return x; }

    static int& _mod_assign(int& x, int mod) { return x %= mod; }
    static long long& _mod_assign(long long& x, long long mod) { return x %= mod; }
};


#undef FOR
#endif
