#include <bits/stdc++.h>
using namespace std;

int main() {
	set<string> dict;

	string s;
	while (cin >> s)
		dict.insert(s);

	for (string w : dict) {
		bool f = false;
		for (int i=1; i<w.size(); i++) {
			string l = w.substr(0, i);
			string r = w.substr(i);
			if (*dict.lower_bound(l) == l
				&& *dict.lower_bound(r) == r) {
				f = true;
			}
		}
		if (f) cout << w << '\n';
	}

	return 0;
}
