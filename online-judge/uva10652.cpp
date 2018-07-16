// uva10652
// convex hull
#include <bits/stdc++.h>
#define FOR(i,end) for (int i=0; i<end; ++i)
using namespace std;

typedef complex<double> Vec;

Vec rotate(Vec v, double deg) {
    return Vec(v * polar(1.0, acos(-1) * deg / 180));
}

double cross(Vec a, Vec b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

int sgn(double x) {
    double EPS = 1e-10;
    if (x < -EPS) return -1;
    else if (x > EPS) return 1;
    else return 0;
}

vector<Vec> pt; // points
Vec hull[6000]; // convex hull

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while (cin >> n) {
        double box = 0;
        pt.clear();
        while (n--) {
            double w, h, a, x, y;
            cin >> x >> y >> w >> h >> a;
            Vec c(x, y);
            pt.push_back(c + rotate(Vec(w/2, h/2), -a));
            pt.push_back(c + rotate(Vec(w/2, -h/2), -a));
            pt.push_back(c + rotate(Vec(-w/2, h/2), -a));
            pt.push_back(c + rotate(Vec(-w/2, -h/2), -a));
            box += w * h;
        }

        Vec btm = *min_element(pt.begin(), pt.end(),
            [](Vec a, Vec b) {
                return sgn(a.imag() - b.imag()) < 0; }); // min y

        sort(pt.begin(), pt.end(),
            [&btm](Vec a, Vec b) {
                if (a == btm) return true;
                else if (b == btm) return false;
                else return sgn(cross(a - btm, b - btm)) > 0; });

        hull[0] = pt[0];
        hull[1] = pt[1];
        int sz = 2;
        for (int i=2; i<(int)pt.size(); i++) {
            while (sgn(cross(hull[sz-1] - hull[sz-2], pt[i] - hull[sz-1])) <= 0) sz--;
            hull[sz++] = pt[i];
        }

        double area = 0;
        FOR(i, sz)
            area += cross(hull[i], hull[(i+1) % sz]);
        cout << fixed << setprecision(1) << 200 * box / area << " %\n";
    }
    return 0;
}
