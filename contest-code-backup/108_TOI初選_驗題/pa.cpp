// soytw
// at time t (minute):
// 6t - 0.5t = 360n ± x
// 11t - 720n = ±2x (t, n, 2x ∈ Z)
// get:
// { n = 11k + 4x,
//   t = 720k + 262x (k ∈ Z)
// or
// { n = 11m - 4x,
//   t = 720m - 262x (m ∈ Z)
// with restriction: 0 ≤ t < 1440
// get:
// -262x/720 ≤ k < -262x/720 + 2
// 262x/720 ≤ m < 262x/720 + 2

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double x;
    while (scanf("%lf", &x) == 1) {
        int k1 = ceil(-x * 262 / 720);
        int k2 = ceil(-x * 262 / 720 + 2) - 1;
        int m1 = ceil(x * 262 / 720);
        int m2 = ceil(x * 262 / 720 + 2) - 1;

        int ans = (k2 - k1 + 1) + (m2 - m1 + 1);
        for (int k=k1; k<=k2; k++)
            for (int m=m1; m<=m2; m++)
                if (720 * k + 262 * x == 720 * m - 262 * x)
                    ans--;
        printf("%d\n", ans);
    }
    return 0;
}
