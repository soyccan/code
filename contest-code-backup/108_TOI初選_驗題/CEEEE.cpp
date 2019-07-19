

#include<bits/stdc++.h>
using namespace std;
//E
int main() {

    int a,b,d1,d2,d3,l[10002],det=1,cou=0;
    long long de;
    scanf ("%d",&a);
    scanf ("%d",&b);
    scanf ("%d",&de);
    for (int q=1;q<=a;q++) {
        scanf ("%d",&l[q]);
    }
    for (int q=1;q<=b;q++) {
        scanf ("%d",&d1);
        scanf ("%d",&d2);
        scanf ("%d",&d3);
        if (d1 == 1) {          //change
            l[d2] = d3;
        }
        else {                  //play
            for (int w=d2;w<=d3;w++) {
                for (int e=w;e<=d3;e++) {
                    for (int t=w;t<=e;t++) {
                    det*=l[t];
                    }
                    if (det<=de&&det!=0) {cou++;}
                    det=1;
                }

            }
        printf ("%d\n",cou);
        cou=0;
        }

    }

    return 0;
}
