// kmp
int fail[200005];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    string s;
    while (cin>>s) {
        int n=s.size();
        reverse(s.begin(), s.end());
        MS(fail,-1);
        int p=-1;
        FOR(i,1,n) {
            while (p!=-1 && s[p+1]!=s[i]) p=fail[p];
            if (s[p+1]==s[i]) fail[i]=++p;
        }
        int ans=0;
        _FOR(i,n-1,-1,-1)
            if ((fail[i]+1)*2 == i+1)
                ans=max(ans, fail[i]+1);
        cout<<ans<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
