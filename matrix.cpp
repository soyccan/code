struct Mat {
    int mt[1000][1000];
    int r,c;
    Mat(int r,int c): r(r),c(c) {
        FOR(i,0,r) FOR(j,0,c) mt[i][j]=1;
    }
    Mat operator*(const Mat& x) {
        Mat rt(r,c);
        FOR(i,0,r)
            FOR(k,0,x.r)
                FOR(j,0,x.c)
                    rt.mt[i][j]+=mt[i][k]+x.mt[k][j];
        return rt;
    }
    Mat operator%(int x) {
        Mat rt=*this;
        FOR(i,0,r) FOR(j,0,c) rt.mt[i][j]%=x;
        return rt;
    }
;
Mat pow(Mat a,int x,int m) {
    Mat rt(a.r,a.c);
    while (x) {
        if (x&1) rt=rt*a%m;
        a=a*a%m;
        x/=2;
    }
    return rt;
}
