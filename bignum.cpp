#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
using namespace std;
class BigNum {
private:
    vector<int> __num;
public:
    // bool sign; // >=0: false;  <0: true
    BigNum(long long x=0) {
        // if (x < 0) {
        //     sign = 1;
        //     x = -x;
        // } else {
        //     sign = 0;
        // }
        while (x) {
            __num.push_back(x%10);
            x /= 10;
        }
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
        for (int i=0; i<__num.size()-1; i++)
            if (__num[i] >= 10)
                __num[i+1] += __num[i] / 10,
                __num[i] %= 10;
            else if (__num[i] < 0) {
                __num[i+1] -= __num[i] / 10;
                if (__num[i] % 10 != 0)
                    __num[i+1]--;
                __num[i] = 10 + __num[i]%(-10);
            }
        while (__num.back() == 0)
            __num.pop_back();
    }
    bool negative() {
        return __num.back() < 0;
    }
};
BigNum operator+(BigNum x, const BigNum& y) {
    if (!x.negative() && !y.negative()) {
        x.resize(max(x.size(), y.size())+1);
        for (int i=0; i<y.size(); i++)
            x[i] += y[i];
        x.carry();
        return x;
    }
    else if (x.negative() && y.negative())
        return -((-x) + (-y));
    else if (!x.negative() && y.negative())
        return x - (-y);
    else if (x.negative() && !y.negative())
        return -((-x) - y);
}
BigNum operator-(const BigNum& x) {
    BigNum r = x;
    r[r.size()-1] = -r[r.size()-1];
    return r;
}
BigNum operator-(BigNum x, const BigNum& y) {
    if (!x.negative() && !y.negative()) {
        x.resize(max(x.size(), y.size())+1);
        for (int i=0; i<y.size(); i++)
            x[i] -= y[i];
        x.carry();
        return x;
    }
    else if (x.negative() && y.negative())
        return -((-x) - (-y));
    else if (!x.negative() && y.negative())
        return x + (-y);
    else if (x.negative() && !y.negative())
        return -((-x) + (-y));
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
    if (x.size() != y.size())
        return false;
    for (int i=0; i<x.size(); i++)
        if (x[i] != y[i])
            return false;
    return true;
}
bool operator<(const BigNum& x, const BigNum& y) {
    if (y == 0)
        return x.negative();
    else
        return x-y < 0;
}
bool operator>(const BigNum& x, const BigNum& y) {
    return !(x<y) && !(x==y);
}
bool operator<=(const BigNum& x, const BigNum& y) {
    return (x<y) || (x==y);
}
bool operator>=(const BigNum& x, const BigNum& y) {
    return !(x<y);
}
ostream& operator<<(ostream& os, const BigNum& x) {
    string s;
    for (int i=x.size()-1; i>=0; i--)
        s.push_back('0'+x[i]);
    return os << s;
}
int main() {
    BigNum x(-91243),y(68759);
    cout<<(x-y);
    return 0;
}
