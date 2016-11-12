#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::ostream;
using std::istream;

class BigNum {
private:
    vector<int> __num;
public:
    BigNum(long long x=0) {
        bool neg = false;
        if (x < 0) {
            neg = true;
            x = -x;
        }
        while (x) {
            __num.push_back(x%10);
            x /= 10;
        }
        if (neg)
            __num.back() = -__num.back();
    }
    void resize(size_t len) {
        __num.resize(len);
    }
    size_t size() const {
        return __num.size();
    }
    int& operator[](size_t index) {
        // if (index < __num.size())
            return __num.at(index);
        // else
        //     TODO: raise exception
    }
    const int& operator[](size_t index) const {
        // if (index < __num.size())
            return __num.at(index);
        // else
        //     TODO: raise exception
    }
    void carry() {
        for (int i=1; i<__num.size(); i++) {
            if (__num[i-1] >= 10) {
                __num[i] += __num[i-1] / 10;
                __num[i-1] %= 10;
            } else if (__num[i-1] < 0) {
                __num[i]--;
                __num[i-1] += 10;
            }
        }
        while (__num.back() == 0)
            __num.pop_back();
    }
    bool negative() const {
        return __num.back() < 0;
    }
    bool zero() const {
        for (int i=0; i<__num.size(); i++)
            if (__num[i] != 0)
                return false;
        return true;
    }
};
BigNum operator-(const BigNum& x) {
    BigNum r = x;
    r[r.size()-1] = -r[r.size()-1];
    return r;
}
bool __equal(const BigNum& x, const BigNum& y) {
    if (x.size() != y.size())
        return false;
    for (int i=0; i<x.size(); i++)
        if (x[i] != y[i])
            return false;
    return true;
}
bool __less(const BigNum& x, const BigNum& y) {
    if (x.size() != y.size())
        return x.size() < y.size();
    for (int i=x.size()-1; i>=0; i--)
        if (x[i] != y[i])
            return x[i] < y[i];
    return false;
}
BigNum abs(const BigNum& x) {
    if (x.negative()) return -x;
    else return x;
}
BigNum __add(const BigNum& x, const BigNum& y) {
    // require x>0, y>0
    BigNum r = x;
    r.resize(max(x.size(), y.size())+1);
    for (int i=0; i<y.size(); i++)
        r[i] += y[i];
    r.carry();
    return r;
}
BigNum __subtract(const BigNum& x, const BigNum& y) {
    // require x>0, y>0
    if (!__less(x, y)) swap(x, y);
    BigNum r = x;
    r.resize(max(x.size(), y.size()));
    for (int i=0; i<y.size(); i++)
        r[i] -= y[i];
    r.carry();
    return r;
}
BigNum operator+(const BigNum& x, const BigNum& y) {
    if (x.negative() == y.negative())
        return __add(abs(x), abs(y));
    else
        return __subtract(abs(x), abs(y));
    // if (!x.negative() && !y.negative())
    //     return __add(x, y);
    // else if (x.negative() && y.negative())
    //     return -__add(-x, -y);
    // else if (!x.negative() && y.negative() && !__less(abs(x), abs(y)))
    //     return __subtract(x, -y);
    // else if (!x.negative() && y.negative() && __less(abs(x), abs(y)))
    //     return -__subtract(-y, x);
    // else if (x.negative() && !y.negative() && !__less(abs(x), abs(y)))
    //     return -__subtract(-x, y);
    // else if (x.negative() && !y.negative() && __less(abs(x), abs(y)))
    //     return __subtract(y, -x);
}
BigNum operator-(const BigNum& x, const BigNum& y) {
    if (!x.negative() && !y.negative())
    else if (x.negative() && y.negative())
    else if (!x.negative() && y.negative())
    else if (x.negative() && !y.negative())
}
BigNum operator*(const BigNum& x, const BigNum& y) {
    BigNum r;
    r.resize(x.size()+y.size()+1);
    for (int i=0; i<x.size(); i++)
        for (int j=0; j<y.size(); j++)
            r[i+j] += x[i] * y[j];
    r.carry();
    return r;
}
bool operator==(const BigNum& x, const BigNum& y) {
    return __equal(x, y);
}
bool operator<(const BigNum& x, const BigNum& y) {
    return __less(x, y);
}
bool operator>(const BigNum& x, const BigNum& y) {
    return !__less(x, y) && !__equal(x, y);
}
bool operator<=(const BigNum& x, const BigNum& y) {
    return __less(x, y) || __equal(x, y);
}
bool operator>=(const BigNum& x, const BigNum& y) {
    return !__less(x, y);
}
ostream& operator<<(ostream& os, const BigNum& x) {
    for (int i=x.size()-1; i>=0; i--)
        os << x[i];
    return os;
}
istream& operator>>(istream& is, BigNum& x) {
    x = BigNum(0);
    char ch;
    bool neg = false;
    if (is.peek() == '-')
        neg = true;
    while (is.get(ch))  {
        if (isdigit(ch))
            x = x*10 + (ch-'0');
    }
    if (neg) x = -x;
    return is;
}
int main() {
    int a,b;
    while (cin>>a>>b) {
        BigNum x=a, y=b;
        cout<<a<<" + "<<b<<" = "<<a+b<<"   "<<x<<" + "<<y<<" = "<<x+y<<endl;
        cout<<a<<" - "<<b<<" = "<<a-b<<"   "<<x<<" - "<<y<<" = "<<x-y<<endl;
    }
    return 0;
}
