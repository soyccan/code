// TODO: inverse matrix and augmented matrix
#ifndef _MATRIX_H
#define _MATRIX_H
#define FOR(i,start,end) for (std::size_t i=start; i<end; ++i)

#include <vector>
#include <stdexcept>
#include <ostream>
#include <cstddef>
#include <algorithm>
#include <type_traits>

namespace matrix {
    const long double EPS = 1e-10;

    inline int sgn(long double x) {
        if (x < -EPS) return -1;
        else if (x > EPS) return 1;
        else return 0;
    }

    template<typename T = long double,
             typename Allocator = std::allocator<T>>
    class Matrix {
    public:
        Matrix() {
            _rows = _cols = 0;
        }
        Matrix(std::size_t rows, std::size_t cols) {
            // [TODO] initializer list
            _arr.resize(rows, std::vector<T>(cols));
            _rows = rows;
            _cols = cols;
        }
        std::size_t getcols() const {
            return _cols;
        }
        std::size_t getrows() const {
            return _rows;
        }
        bool empty() const {
            return _cols == 0 && _rows == 0;
        }
        const std::vector<T>& operator[](std::size_t index) const {
            return _arr[index];
        }
        std::vector<T>& operator[](std::size_t index) {
            return _arr[index];
        }
        Matrix& operator+=(const Matrix& x) {
            if (_rows != x._rows || _cols != x._cols)
                throw std::invalid_argument("matrix size not match");
            FOR(i, 0, _rows)
                FOR(j, 0, _cols)
                    _arr[i][j] += x[i][j];
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

        friend Matrix operator-(Matrix x) { return x *= -1; }
        friend Matrix operator+(Matrix x, const Matrix& y) { return x += y; }
        friend Matrix operator-(Matrix x, const Matrix& y) { return x -= y; }
        friend Matrix operator*(Matrix x, T y) { return x *= y; }
        friend Matrix operator/(Matrix x, T y) { return x /= y; }
        friend Matrix operator%(Matrix x, T y) { return x %= y; }
        friend std::ostream& operator<<(std::ostream& os, const Matrix& x) {
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
        friend bool operator==(const Matrix& x, const Matrix& y) {
            if (x.getrows() != y.getrows() || x.getcols() != y.getcols())
                return false;
            FOR(i, 0, x.getrows())
                FOR(j, 0, x.getcols())
                    if (sgn(x[i][j] - y[i][j]) != 0)
                        return false;
            return true;
        }
        friend bool operator!=(const Matrix& x, const Matrix& y) {
            return !(x == y);
        }

        int _gauss() {
            // Gaussian elimination
            // transform matrix into row echelon form
            // only use row switching and row addition
            // can be used to calculate determinant
            bool sign = 0; // whether determinant should change sign (after row switching)
            FOR(i, 0, _rows) {
                for (std::size_t j = i+1; j < _rows && sgn(_arr[i][i]) == 0; ++j) {
                    std::swap(_arr[i], _arr[j]);
                    sign = !sign;
                }
                if (_arr[i][i] == 0)
                    // fail
                    return -1;

                FOR(j, i+1, _rows) {
                    T t = _arr[j][i] / _arr[i][i];
                    FOR(k, 0, _cols) {
                        _arr[j][k] -= _arr[i][k] * t;
                    }
                    _arr[j][i] = 0;
                }
            }
            return sign;
        }
        int _gauss_jordan() {
            // Gauss-Jordan elimination
            // transform matrix into "reduced" row echelon form
            // use row switching, row multiplication and row addition
            int res = _gauss();
            FOR(i, 0, _rows) {
                T s = _arr[i][i];
                FOR(k, i, _cols)
                    if (sgn(_arr[i][i]) != 0)
                        _arr[i][k] /= s;
                FOR(j, 0, i) {
                    T t = _arr[j][i];
                    FOR(k, i, _cols)
                        _arr[j][k] -= _arr[i][k] * t;
                }
            }
            return res;
        }

    private:
        std::vector< std::vector<T> > _arr;
        std::size_t _rows, _cols;
    };

    template<typename T = long double>
    class SquareMatrix : public Matrix<T> {
    public:
        SquareMatrix(std::size_t size = 0): Matrix<T>(size, size) {}
    };



    template<typename T>
    Matrix<T> augment(const Matrix<T>& x, const Matrix<T>& y) {
        if (x.getrows() != y.getrows())
            throw std::invalid_argument("different row count");
        Matrix<T> z(x.getrows(), x.getcols() + y.getcols());
        FOR(i, 0, x.getrows()) {
            FOR(j, 0, x.getcols())
                z[i][j] = x[i][j];
            FOR(j, 0, y.getcols())
                z[i][ j+x.getcols() ] = y[i][j];
        }
        return z;
    }

    template<typename T>
    void _check_mul(const Matrix<T>& x, const Matrix<T>& y) {
        if (x.getcols() != y.getrows())
            throw std::invalid_argument(
                "matrix size not suitable for multiplying\n"
                "it should be: (m*n) and (n*p) respectively\n"
                "try changing their order");
    }

    template<typename T>
    Matrix<T> mul(const Matrix<T>& x, const Matrix<T>& y) {
        _check_mul(x, y);
        Matrix<T> z(x.getrows(), y.getcols());
        FOR(i, 0, x.getrows())
            FOR(j, 0, y.getcols())
                FOR(k, 0, x.getcols())
                    z[i][j] += x[i][k] * y[k][j];
        return z;
    }

    template<typename T, typename Int>
    Matrix<T> mul(const Matrix<T>& x, const Matrix<T>& y, Int mod) {
        // modulo acts only when T == Int
        static_assert(std::is_integral<Int>::value, "modulo not integral");
        _check_mul(x, y);
        Matrix<T> z(x.getrows(), y.getcols());
        FOR(i, 0, x.getrows())
            FOR(j, 0, y.getcols())
                FOR(k, 0, x.getcols()) {
                    z[i][j] += x[i][k] * y[k][j];
                    z[i][j] %= mod;
                }
        return z;
    }

    template<typename T, typename Int>
    SquareMatrix<T> pow(const SquareMatrix<T>& matrix, Int exp) {
        // quick exponentiation
        static_assert(std::is_integral<Int>::value, "exponent not integral");
        SquareMatrix<T> x = matrix;
        SquareMatrix<T> res = identity_matrix(matrix.getrows());
        while (exp > 0) {
            if (exp % 2 == 1)
                res = mul(x, res);
            x = mul(x, x);
            exp /= 2;
        }
        return res;
    }

    template<typename T, typename Int>
    SquareMatrix<T> pow(const SquareMatrix<T>& matrix, Int exp, Int mod) {
        // quick exponentiation
        static_assert(std::is_integral<Int>::value, "modulo or exponent not integral");
        SquareMatrix<T> x = matrix;
        SquareMatrix<T> res = identity_matrix(matrix.getrows());
        while (exp > 0) {
            if (exp % 2 == 1)
                res = mul(x, res, mod);
            x = mul(x, x, mod);
            exp /= 2;
        }
        return res;
    }

    template<typename T>
    Matrix<T> transpose(const Matrix<T>& x) {
        Matrix<T> y(x.cols, x.rows);
        FOR(i, 0, y.rows)
            FOR(j, 0, y.cols)
                y[i][j] = x[j][i];
        return y;
    }

    template<typename T>
    SquareMatrix<T> upper_triangular(const SquareMatrix<T>& matrix) {
        SquareMatrix<T> res = matrix;
        res._gauss();
        return res;
    }

    template<typename T>
    SquareMatrix<T> identity_matrix(std::size_t size) {
        SquareMatrix<T> x(size);
        FOR(i, 0, size) x[i][i]=1;
        return x;
    }

    template<typename T>
    SquareMatrix<T> inverse(const SquareMatrix<T>& matrix) {
        // return empty matrix when matrix not invertible
        SquareMatrix<T> I = identity_matrix<T>(matrix.getrows());
        Matrix<T> aug = augment(matrix, I);
        aug._gauss_jordan();

        SquareMatrix<T> res(matrix.getrows());
        FOR(i, 0, matrix.getrows()) {
            FOR(j, 0, matrix.getcols()) {
                if ((i == j && sgn(aug[i][j] - 1) != 0)
                    || (i != j && sgn(aug[i][j]) != 0)) return SquareMatrix<T>();
                res[i][j] = aug[i][ j+matrix.getcols() ];
            }
        }
        return res;
    }

    template<typename T>
    T determinant(const SquareMatrix<T>& x) {
        SquareMatrix<T> y = x;
        int sign = y._gauss();
        T res = 1;
        FOR(i, 0, y.getrows()) res *= y[i][i];
        if (sign == 1) return -res;
        else if (sign == 0) return res;
        else return 0;
    }
}

#undef FOR
#endif
