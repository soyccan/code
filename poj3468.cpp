// poj3468
// segment tree with lazy flag
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Node {
    Node *lc,*rc;
    int l,r;
    ll add, sum;
};
int arr[100005];

void build(Node* nd, int l, int r) {
    nd->lc = new Node();
    nd->rc = new Node();
    nd->l = l;
    nd->r = r;
    nd->add = 0;
    if (l == r)
        nd->sum = arr[l];
    else {
        int m = (l+r)/2;
        build(nd->lc, l, m);
        build(nd->rc, m+1, r);
        nd->sum = nd->lc->sum + nd->rc->sum;
    }
}
void add(Node* nd, int l, int r, ll v) {
    printf("ADD add:%lld sum:%lld (%d %d) nd:(%d %d)\n", nd->add, nd->sum, l,r,nd->l,nd->r);
    if (nd->add) {
        nd->sum += nd->add*(nd->r - nd->l + 1);
        nd->lc->add += nd->add;
        nd->rc->add += nd->add;
        nd->add = 0;
    }

    int m = (nd->l + nd->r)/2;
    if (l == nd->l && r == nd->r)
        nd->add += v;
    else if (r <= m)
        add(nd->lc, l, r, v);
    else if (l > m)
        add(nd->rc, l, r, v);
    else {
        add(nd->lc, l, m, v);
        add(nd->rc, m+1, r, v);
    }
}
ll sum(Node* nd, int l, int r) {
    printf("SUM add:%lld sum:%lld (%d %d) nd:(%d %d)\n", nd->add, nd->sum, l,r,nd->l,nd->r);
    if (nd->add) {
        nd->sum += nd->add*(nd->r - nd->l + 1);
        nd->lc->add += nd->add;
        nd->rc->add += nd->add;
        nd->add = 0;
    }

    int m = (nd->l + nd->r)/2;
    if (l == nd->l && r == nd->r)
        return nd->sum;
    else if (r <= m)
        return sum(nd->lc, l, r);
    else if (l > m)
        return sum(nd->rc, l, r);
    else
        return sum(nd->lc, l, m) + sum(nd->rc, m+1, r);
}
int main() {
    int n,q,a,b,v;
    char cmd[5];
    scanf("%d%d",&n,&q);
    for (int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    Node* root = new Node();
    build(root,1,n);
    while (q--) {
        scanf("%s%d%d",cmd,&a,&b);
        if (a > b) swap(a,b);
        if (cmd[0] == 'C') {
            scanf("%d",&v);
            add(root,a,b,v);
        } else {
            printf("%lld\n",sum(root,a,b));
        }
    }
    return 0;
}
