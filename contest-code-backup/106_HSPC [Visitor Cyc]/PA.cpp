#include<bits/stdc++.h>
using namespace std;
string yee = "NKUSIE";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string s;
    getline(cin,s);
	while(t--)
	{
		getline(cin,s);
		stringstream ss;
		ss << s;
		map<char,int> cnt;
		int ans = 132546;
		while(ss >> s)
		{
			for(int i=0;i<s.size();i++)
			    cnt[s[i]]++;
		}
		ans = min(ans,cnt['C']/2);
		for(int i=0;i<yee.size();i++)
		    ans = min(ans,cnt[yee[i]]);
		cout << ans << endl;
	} 
	return 0;
}
/*
5
WELCOME TO NCKU CSIE
CSIE IS ONE OF THE BEST DEPARTMENTS IN NCKU
NCKU CSIE IS ONE OF THE BEST CSIE IN TAIWAN
NCKU CSIE STANDS FOR NATIONAL CHENG KUNG UNIVERSITY COMPUTER SCIENCE AND INFORMATION ENGINEERING
HOW ABOUT CCEKNISU CHEER UP
*/
