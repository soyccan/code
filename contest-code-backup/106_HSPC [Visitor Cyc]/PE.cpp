#include<bits/stdc++.h>
#define pii pair<int,int>
#define maxn 105
using namespace std;
int N,M;
struct edge{
	int u,v,cost;
}E[maxn*maxn];
bool operator < (edge a,edge b)
{
	return a.cost < b.cost;
}
vector<pii> G[maxn];
inline void input()
{
	cin >> N >> M;
	for(int i=1;i<=N;i++)    G[i].clear();
	for(int i=0;i<M;i++)
		cin >> E[i].u >> E[i].v >> E[i].cost;
}
bool cho[maxn*maxn];
int pa[maxn];
int Find(int x)
{
	return x == pa[x] ? x : pa[x] = Find(pa[x]);
}
inline void Union(int x,int y)
{
	pa[Find(x)] = Find(y);
}
int ans[2];
inline void build()
{
	for(int i=1;i<=N;i++)    pa[i] = i;
	memset(cho,false,sizeof cho);
    sort(E,E+M);
    int cnt = 0;
    ans[0] = 0;
    for(int i=0;i<M;i++)
    {
    	int u = E[i].u;
    	int v = E[i].v;
    	int cost = E[i].cost;
    	if(Find(u) != Find(v) )
    	{
    	    Union(u,v) , ans[0] += cost , cho[i] = true , cnt++;
			G[u].push_back(pii{v,cost});
			G[v].push_back(pii{u,cost});
		}
    	if(cnt == N-1)    break;
	}
}
int dis[maxn][maxn];
bool yee[maxn];
bool yaz[maxn];
void dfs(int u,int top,int cost)
{
	yaz[u] = true;
	dis[top][u] = dis[u][top] = cost;
	for(pii e : G[u])
	{
		int v = e.first;
		if(yaz[v])    continue;
		dfs(v,top,max(cost,e.second));
	}
}
inline void solve()
{
	memset(yee,false,sizeof yee);
	ans[1] = 12345678;
	for(int i=0;i<M;i++)
	    if(!cho[i])
		{
			int u = E[i].u;
			int v = E[i].v;
			int cost = E[i].cost;
			if(!yee[u] && !yee[v])
			{
				memset(yaz,false,sizeof yaz);
			    yee[u] = true , dfs(u,u,0);
			}
			ans[1] = min(ans[1],ans[0]+cost-dis[u][v]);
		} 
	cout << ans[0] << " " << ans[1] << endl;
}
int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		input();
		build();
		solve();
	}
	return 0;
}
/*
2
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66
9 14
1 2 4
1 8 8
2 8 11
3 2 8
8 9 7
8 7 1
7 9 6
9 3 2
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
5 6 10
*/
