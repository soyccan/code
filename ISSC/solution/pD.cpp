#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef vector<int> vec;
typedef vector<vec> mat;
int MOD=0;
mat mul(mat A,mat B)
{
	mat C(2,vec(2));
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<2;++j)
		{
			for(int k=0;k<2;++k)
			{
				C[i][j]+=A[i][k]*B[k][j];
				C[i][j]%=MOD;
			}
		}
	}
	return C;
}
mat POW(mat A,int p)
{
	mat base=A,res(2,vec(2));
	res[0][0]=res[1][1]=1;
	while(p)
	{
		//cout<<p<<endl;
		if(p&1) res=mul(res,base);
		base=mul(base,base);
		p>>=1;
	}
	return res;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);

    int n,m;
    while(cin>>n)
    {
    	if(n==0) break;
    	cin>>m;
    	MOD=1;
    	for(int i=1;i<=m;++i) MOD*=2;
	    mat tp(2,vec(2));
	    tp[0][0]=0;
	    tp[0][1]=1;
	    tp[1][0]=1;
	    tp[1][1]=1;
	    mat ans=POW(tp,n+1);
	    cout<<ans[0][0]<<endl;
	}
	return 0;
}


