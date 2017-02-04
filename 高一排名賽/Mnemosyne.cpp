#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	long long cnta=0, cntb=0;
	for (char c : a)
		if (c != '0') cnta++;
	for (char c : b)
		if (c != '0') cntb++;
	cout << cnta*cntb << endl;
	return 0;
}

