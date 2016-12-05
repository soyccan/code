struct _Float {
    const long double EPS = 1e-10;
    long double n;
    _Float operator==(_Float x) {
        return -EPS<=n-x.n && n-x.n<=EPS;
    }
    _Float operator<=(_Float x) {
        return n<=x.n+EPS;
    }
    _Float operator>=(_Float x) {
        return n>=x.n-EPS;
    }
    _Float operator>(_Float x) {
        return n>=x.n+EPS;
    }
    _Float operator<(_Float x) {
        return n<=x.n-EPS;
    }
};
