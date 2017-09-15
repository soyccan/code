#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define maxn 1005
int n,x[maxn],y[maxn],pa[maxn],d[maxn][maxn];
struct Edge{
	int a,b,cost;
}es[maxn*maxn];
bool cmp(Edge a,Edge b)
{
	return a.cost<b.cost;
}
void init()
{
	for(int i=0;i<=n;++i) pa[i]=i;
}
int find(int x)
{
	if(pa[x]==x) return x;
	return pa[x]=find(pa[x]);
}
void U(int x,int y)
{
	x=find(x);y=find(y);
	pa[x]=y;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    while(cin>>n,n!=0)
    {
    	//int a,b;
    	for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    	memset(d,0,sizeof(d));
    	int r=0;
    	for(int i=1;i<=n;++i)
    		for(int j=1;j<=n;++j)
    			d[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]),es[r].a=i,es[r].b=j,es[r].cost=d[i][j],r++;
    	//cout<<"r="<<r<<endl;
    	sort(es,es+r,cmp);
    	init();
    	int ans=0;
    	for(int i=0;i<r;++i)
    	{
    		Edge e=es[i];
    		if(find(e.a)!=find(e.b))
    		{
    			U(e.a,e.b);
    			ans+=e.cost;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
/*
4
3 8
0 6
3 -1
1 2
3
0 0
-1 -2
5 0
0
*/

