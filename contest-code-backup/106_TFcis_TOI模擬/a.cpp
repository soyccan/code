#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
struct Node {
    Node *l,*r;
};
set<int> G[100005];
int pa[100005];
bool rch[100005];
vector<pair<int,int>> ans4;
void out4(int i,int x,int p) {
    ans4.push_back({i,x});
    vector<int> v;
    for (int y:G[x]) if (y!=p) v.push_back(y);
    if (v.size()==1) {
        int y=v[0];
        if (rch[y]) out4(i*2+1,y,x);
        else out4(i*2,y,x);
    } else if (v.size()==2) {
        int y1=v[0], y2=v[1];
        if (y1>y2) swap(y1,y2);
        out4(i*2,y1,x);
        out4(i*2+1,y2,x);
    }
}
void findpa(int x,int p) {
    for (int y:G[x]) {
        if (y==p)continue;
        pa[y]=x;
        findpa(y,x);
    }
}
main() {
#ifndef soytw
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,I,J,x,y; string s;
    while (cin>>n>>I>>J) {
        MS(rch,0);
        MS(pa,-1);
        if (I==1) {
            FOR(i,0,n) {
                getline(cin,s);
                stringstream ss(s);
                ss>>x;
                while (ss>>y) {
                    G[x].insert(y);
                    G[y].insert(x);
                }
            }
        } else if (I==2) {
            while (cin>>x>>y) {
                G[x].insert(y);
                G[y].insert(x);
            }
        } else if (I==3) {
            FOR(i,0,n) {
                cin>>x;
                FOR(j,1,n+1) {
                    cin>>y;
                    if (y) {
                        G[x].insert(j);
                        G[j].insert(x);
                    }
                }
            }
        } else if (I==4) {
            map<int,int> mp;
            while (cin>>x>>y) {
                mp[x]=y;
            }
            FOR(i,0,1<<n) {
                x=mp[i], y=mp[i*2];
                if (x&&y) {
                    G[x].insert(y);
                    G[y].insert(x);
                    rch[y]=0;
                }
                x=mp[i], y=mp[i*2+1];
                if (x&&y) {
                    G[x].insert(y);
                    G[y].insert(x);
                    rch[y]=1;
                }
            }
        } else if (I==5) {
            FOR(i,2,n+1) {
                cin>>x;
                G[x].insert(i);
                G[i].insert(x);
                pa[i]=x;
            }
        }

        // output
        if (J==1) {
            FOR(i,1,n+1) {
                cout<<i<<' ';
                for (int j : G[i]) cout<<j<<' ';
                cout<<'\n';
            }
        } else if (J==2) {
            FOR(i,1,n+1) {
                for (int j : G[i])
                    if (i<j)
                        cout<<i<<' '<<j<<'\n';
            }
        } else if (J==3) {
            FOR(i,1,n+1) {
                cout<<i<<' ';
                FOR(j,1,n+1)
                    if (G[i].find(j)!=G[i].end())
                        cout<<"1 ";
                    else
                        cout<<"0 ";
                cout<<'\n';
            }
        } else if (J==4) {
            ans4.clear();
            out4(1,1,-1);
            sort(ans4.begin(), ans4.end());
            for (pair<int,int> e :ans4)
                cout<<e.first<<' '<<e.second<<'\n';
        } else if (J==5) {
            findpa(1,-1);
            FOR(i,2,n+1) {
                cout<<pa[i]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
