#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> G[1000005];
vector<string> name;
int pa[1000005];
bool cmp(string a, string b) {
	int i=0;
	while (i<a.size() && i<b.size()) {
		if (a[i]!=b[i]) {
			if (isupper(a[i])&&islower(b[i])) return true;
			else if (isupper(b[i])&&islower(a[i])) return false;
			else return a[i]<b[i];
		}
		i++;
	}
	if (i == a.size()) return true;
	else return false;
}
inline string tidy(string s) {
	string res;
	for (char c : s) if (c != '\\') res.push_back(c);
	// cout<<"tidy:"<<res<<endl;
	return res;
}
inline vector<string> split(string path) {
	vector<string> v;
	if (path == "/") return v;
	const char* tmp = path.c_str();
	char str[10000];
	strcpy(str,tmp);
	char* ptr = strtok(str,"/");
	v.push_back(string(ptr));
	while (ptr=strtok(NULL,"/")) {
		v.push_back(string(ptr));
	}
	return v;
}
int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	string cmd,arg;
	int cwd = 0;
	name.push_back("/");
	while (cin>>cmd) {
		// cout<<"----cwd:"<<name[cwd]<<endl;
		if (cmd == "cd") {
			scanf("\n");
			getline(cin,arg);
			arg = tidy(arg);
			// cout<<"   cd:"<<arg<<endl;
			if (arg[0] == '/') cwd = 0;
			for (string dir : split(arg)) {
				if (dir == ".") continue;
				else if (dir == "..") cwd = pa[cwd];
				else {
					for (int chd : G[cwd])
						if (name[chd] == dir) cwd = chd;
				}
			}
		} else if (cmd == "mkdir"||cmd == "touch") {
			scanf("\n");
			getline(cin,arg);
			arg = tidy(arg);
			// cout<<"   mkdir,touch:"<<arg<<endl;
			int id = name.size();
			name.push_back(arg);
			G[cwd].push_back(id);
			pa[id] = cwd;
		} else if (cmd == "ls") {
			// cout<<"   ls:\n";
			vector<string> v;
			for (int id : G[cwd]) {
				v.push_back(name[id]);
			}
			sort(v.begin(), v.end(), cmp);
			for (string s : v) cout<<s<<endl;
		}
	}
	return 0;
}
