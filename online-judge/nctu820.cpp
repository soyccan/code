// nctu 820 big integer
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x[300], y[300], z[300];
int xl = 0, yl = 0;

void carry() {
    x[xl] = 0;
    for (int i = 0; i < xl; i++) {
        if (x[i] >= 0) {
            x[i+1] += x[i] / 10;
            x[i] %= 10;
        }
    }
    if (x[xl] > 0)
        xl++;
}

void calc(char op) {
    if (yl == 0) return;

    if (op == '+') {
        for (int i = 0; i < max(xl, yl); i++)
            if (i >= xl)
                x[i] = y[i];
            else if (i < yl)
                x[i] += y[i];
        xl = max(xl, yl);
    }
    else if (op == '*') {
        memset(z, 0, sizeof z);
        for (int i = 0; i < xl; i++)
            for (int j = 0; j < yl; j++)
                z[i + j] += x[i] * y[j];
        memcpy(x, z, sizeof x);
        xl = xl + yl;
        while (xl > 1 && x[xl-1] == 0) xl--;
    }
    carry();
    yl = 0;
}

int main() {
#ifdef soyccan
    freopen("in.txt", "r", stdin);
#endif

    int c = 0;
    bool first = true;
    char op = 0;
    while (true) {
        first = true;
        xl = yl = 0;
        while (true) {
            c = getchar();
            if (c == EOF || c == '\n') {
                reverse(y, y + yl);
                calc(op);
                break;
            }
            else if ('0' <= c && c <= '9') {
                if (first)
                    x[xl++] = c - '0';
                else
                    y[yl++] = c - '0';
            }
            else if (c == '+' || c == '*') {
                if (first) {
                    reverse(x, x + xl);
                    first = false;
                }
                reverse(y, y + yl);
                calc(op);
                op = c;
            }
        }
        for (int i = xl - 1; i >= 0; i--)
            putchar('0' + x[i]);
        putchar('\n');
        if (c == EOF) break;
    }
    return 0;
}
