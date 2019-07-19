// uva 10341

#include <bits/stdc++.h>
using namespace std;

int main() {
	double p,q,r,s,t,u;
	while (cin>>p>>q>>r>>s>>t>>u) {
		double l=0, up=1, x, y;
		int n=100;
		while (n--) {
			x = (l+up)/2;
			y = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
			// printf("%g %g %g %g\n", l, up, x, y);
			if (y < 0)
				up=x;
			else
				l=x;
		}
		if (abs(y) <= 1e-8)
			printf("%.4f\n", x);
		else
			printf("No solution\n");
	}
	return 0;
}