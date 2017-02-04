#include <bits/stdc++.h>

using namespace std;
#define log logarr
long long num[519][519],den[519][519];
long double log[519][519];
long double dp[519][519][119];
pair<pair<int,int>,int> pre[519][519][119];
long double _lg2(long long int n,long long int d){
	if(n==0)return -1000000219.;
	return log2(n)-log2(d);
}
int main(){
//	freopen("testdata/0425.in","rt",stdin);
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>num[i][j]>>den[i][j];
			log[i][j]=_lg2(num[i][j],den[i][j]);
		}
	}
	cin>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int m=0;m<=k;m++){
				dp[i][j][m]=-1000000219.;
			}
		}
	}
	dp[1][1][0]=0;pre[1][1][0]={{-1,-1},0};
	dp[1][1][1]=log[1][1];pre[1][1][1]={{-1,-1},0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1&&j==1)continue;
			for(int used=0;used<=k;used++){
				//choose this
				if(used!=k){
					if(dp[i-1][j][used]+log[i][j]>=dp[i][j][used+1]){
						dp[i][j][used+1]=dp[i-1][j][used]+log[i][j];
						pre[i][j][used+1]={{i-1,j},used};
					}
					if(dp[i][j-1][used]+log[i][j]>=dp[i][j][used+1]){
						dp[i][j][used+1]=dp[i][j-1][used]+log[i][j];
						pre[i][j][used+1]={{i,j-1},used};
					}
				}
				//not choose this
				if(dp[i-1][j][used]>=dp[i][j][used]){
					dp[i][j][used]=dp[i-1][j][used];
					pre[i][j][used]={{i-1,j},used};
				}
				if(dp[i][j-1][used]>=dp[i][j][used]){
					dp[i][j][used]=dp[i][j-1][used];
					pre[i][j][used]={{i,j-1},used};
				}
			}
		}
	}
//	cout<<dp[n][n][k]<<endl;
	if(dp[n][n][k]<=-1000000219.){
		cout<<0<<' '<<1<<endl;
		return 0;
	}
	vector<pair<pair<int,int>,int> >dppath;
	dppath.push_back({{n,n},k});
	while(dppath[dppath.size()-1]!=make_pair(make_pair(-1,-1),0)){
		dppath.push_back(
			pre[dppath.back().first.first]
				[dppath.back().first.second][dppath.back().second]);
	}
	reverse(dppath.begin(),dppath.end());
	vector<long long>numl,denl;
	for(int i=1;i<dppath.size();i++){
		if(dppath[i].second!=dppath[i-1].second){
			int x=dppath[i].first.first;
			int y=dppath[i].first.second;
			numl.push_back(num[x][y]);
			denl.push_back(den[x][y]);
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			long long g=__gcd(numl[i],denl[j]);
			numl[i]/=g;
			denl[j]/=g;
		}
	}
	long long finnum=1,finden=1;
	for(int i=0;i<k;i++){
		finnum*=(numl[i]%1000000009);
		finnum%=1000000009;
		finden*=(denl[i]%1000000009);
		finden%=1000000009;
//		cout<<finnum<<' '<<finden<<endl; 
	}
	cout<<finnum<<' '<<finden<<endl;
	return 0;
}
