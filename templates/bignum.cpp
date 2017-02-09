// TODO: negative
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

struct _BigNum {
    vector<int> arr;
    bool neg;
    _BigNum(long long num=0) {
        if (num < 0) {
            neg = true;
            num = -num;
        } else {
            neg = false;
        }
        while (num) {
            arr.push_back(num%10);
            num /= 10;
        }
    }
    _BigNum(string num="0") {
        if (num[0] == '-') {
            neg = true;
        }
        while (num.size()) {
            if (isdigit(num.back())) {
                arr.push_back(num.back()-'0');
                num.pop_back();
            }
        }
    }
    // void resize(size_t len) {
    //     arr.resize(len);
    // }
    // size_t size() const {
    //     return arr.size();
    // }
    // int& operator[](size_t index) {
    //     // if (index < arr.size())
    //         return arr.at(index);
    //     // else
    //     //     TODO: raise exception
    // }
    // const int& operator[](size_t index) const {
    //     // if (index < arr.size())
    //         return arr.at(index);
    //     // else
    //     //     TODO: raise exception
    // }
    void carry() {
        for (int i=1; i<arr.size(); i++) {
            if (arr[i-1] >= 10) {
                arr[i] += arr[i-1] / 10;
                arr[i-1] %= 10;
            // } else if (arr[i-1] < 0) {
            //     arr[i]--;
            //     arr[i-1] += 10;
            }
        }
        while (arr.size() && arr.back() == 0)
            arr.pop_back();
    }
    // bool negative() const {
    //     return arr.back() < 0;
    // }
    // bool zero() const {
    //     for (int i=0; i<arr.size(); i++)
    //         if (arr[i] != 0)
    //             return false;
    //     return true;
    // }
    // _BigNum __add(const _BigNum& x) {
    //     // require x>0, y>0
    //     _BigNum r = *this;
    //     r.resize(max(arr.size(), x.size())+1);
    //     for (int i=0; i<y.size(); i++)
    //         r[i] += y[i];
    //     r.carry();
    //     return r;
    // }
    // _BigNum __subtract(const _BigNum& x, const _BigNum& y) {
    //     // require x>0, y>0
    //     if (!__less(x, y)) swap(x, y);
    //     _BigNum r = x;
    //     r.resize(max(x.size(), y.size()));
    //     for (int i=0; i<y.size(); i++)
    //         r[i] -= y[i];
    //     r.carry();
    //     return r;
    // }
    _BigNum operator+(const _BigNum& x) {
        _BigNum r = *this;
        r.arr.resize(max(arr.size(), x.arr.size())+1);
        for (int i=0; i<x.arr.size(); i++)
            r.arr[i] += x.arr[i];
        r.carry();
        return r;
        // if (x.negative() == y.negative())
        //     return __add(abs(x), abs(y));
        // else
        //     return __subtract(abs(x), abs(y));
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
};
//     _BigNum operator-(const _BigNum& x, const _BigNum& y) {
//         if (!x.negative() && !y.negative())
//         else if (x.negative() && y.negative())
//         else if (!x.negative() && y.negative())
//         else if (x.negative() && !y.negative())
//     }
//     _BigNum operator*(const _BigNum& x, const _BigNum& y) {
//         _BigNum r;
//         r.resize(x.size()+y.size()+1);
//         for (int i=0; i<x.size(); i++)
//             for (int j=0; j<y.size(); j++)
//                 r[i+j] += x[i] * y[j];
//         r.carry();
//         return r;
//     }
//     bool operator==(const _BigNum& x, const _BigNum& y) {
//         return __equal(x, y);
//     }
//     bool operator<(const _BigNum& x, const _BigNum& y) {
//         return __less(x, y);
//     }
//     bool operator>(const _BigNum& x, const _BigNum& y) {
//         return !__less(x, y) && !__equal(x, y);
//     }
//     bool operator<=(const _BigNum& x, const _BigNum& y) {
//         return __less(x, y) || __equal(x, y);
//     }
//     bool operator>=(const _BigNum& x, const _BigNum& y) {
//         return !__less(x, y);
//     }
//     ostream& operator<<(ostream& os, const _BigNum& x) {
//         for (int i=x.size()-1; i>=0; i--)
//             os << x[i];
//         return os;
//     }
//     istream& operator>>(istream& is, _BigNum& x) {
//         return is;
//     }
// };
// _BigNum operator-(const _BigNum& x) {
//     _BigNum r = x;
//     r[r.size()-1] = -r[r.size()-1];
//     return r;
// }
// bool __equal(const _BigNum& x, const _BigNum& y) {
//     if (x.size() != y.size())
//         return false;
//     for (int i=0; i<x.size(); i++)
//         if (x[i] != y[i])
//             return false;
//     return true;
// }
// bool __less(const _BigNum& x, const _BigNum& y) {
//     if (x.size() != y.size())
//         return x.size() < y.size();
//     for (int i=x.size()-1; i>=0; i--)
//         if (x[i] != y[i])
//             return x[i] < y[i];
//     return false;
// }
// _BigNum abs(const _BigNum& x) {
//     if (x.negative()) return -x;
//     else return x;
// }
int main() {
    // int a,b;
    // while (cin>>a>>b) {
    //     _BigNum x=a, y=b;
    //     cout<<a<<" + "<<b<<" = "<<a+b<<"   "<<x<<" + "<<y<<" = "<<x+y<<endl;
    //     cout<<a<<" - "<<b<<" = "<<a-b<<"   "<<x<<" - "<<y<<" = "<<x-y<<endl;
    // }
    return 0;
}
