// uva 441

#include <bits/stdc++.h>
using namespace std;

bool used[20];
int com[10]; // combination
int data[20];

void backtrack(int begin, int end, int num) {
	if (end >= 6) {
		for (int i=0; i<5; i++)
			cout << com[i] << ' ';
		cout << com[5] << '\n';
	} else if (num > com[end]) {
		for (int i=begin; i<=end; i++) {
			if (!used[i]) {
				used[i] = true;
				com[end+1] = data[i];
				backtrack(i, end+1, data[i]);
				used[i] = false;
			}
		}
	}
}

int main() {
	int count = 0;
	int n;
	while (cin >> n && n != 0) {
		if (count++) cout << '\n';
		for (int i=0; i<n; i++)
			cin >> data[i];
		memset(used, false, sizeof used);
		backtrack(0, 0, data[0]);
	}
	return 0;
}