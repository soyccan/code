#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, fail[10005], pos;
	string s,w;

	cin.tie(0);
	ios::sync_with_stdio(0);

	cin>>t;
	while(cin>>w>>s){
		pos = -1;
		fail[0] = -1;
		for (int i=1; i<w.size(); i++) {
			while (pos >= 0 && w[i] != w[pos+1])
				pos = fail[pos];

			if (w[i] == w[pos+1])
				fail[i] = ++pos;
			else
				fail[i] = pos;
		}

		int cnt = 0;
		pos = -1;
		for (int i=0; i<s.size(); i++) {
			while (pos >= 0 && s[i] != w[pos+1])
				pos = fail[pos];

			if (s[i] == w[pos+1])
				pos++;

			if (pos == w.size()-1) {
				cnt++;
				pos = fail[pos];
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}