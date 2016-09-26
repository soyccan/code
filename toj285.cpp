#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x,y;
};
vector<Point> cty;
char arr[205][205];
bool used[205][205];
int dis[205][205][205];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,t,a,b;
    cin>>t;
    while (t--) {
        memset(arr,'#',sizeof arr);
        cin>>N>>M;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                cin>>arr[i][j];
                if (isalpha(arr[i][j]))
                    cty.push_back({i,j});
            }
        }
        for (int i=0; i<cty.size(); i++) {
            queue<Point> q;
            q.push(cty[i]);
            memset(used,0,sizeof used);
            for (int j=1; i<=N; i++)
                for (int k=1; j<=M; j++)
                    dis[i][j][k]=1e8;
            while (q.size()) {
                Point cp=q.front(); q.pop();
                int x=cp.x;
                int y=cp.y;
                cout<<"x:"<<x<<" y:"<<y<<endl;
                for (int j=0; j<4; j++) {
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if (arr[nx][ny]=='.' && !used[nx][ny]) {
                        used[nx][ny]=true;
                        q.push({nx,ny});
                        dis[i][nx][ny]=dis[i][x][y]+1;
                    }
                }
            }
        }
        int ans=-1;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                int sum=0;
                for (int k=0; k<cty.size(); k++)
                    sum+=dis[k][i][j];
                ans=max(ans,sum);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
