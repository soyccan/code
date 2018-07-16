#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	freopen("in.txt", "w", stdout);
	int t = rand()%1000;
	while (t--) {
		int n = rand()%1000000;
		cout << n << '\n';
		while (n--) cout << rand()%2 << ' ';
		cout << '\n';
	}
	return 0;
}

