// tioj 1332
// treap
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int pa[1000005]={0};
struct Node {
    Node *l, *r;
    int pri, key;
    Node(int _key) {
        l = r = 0;
        pri = rand();
        key = _key;
    }
};
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    else if (!b) return a;
    else if (a->pri > b->pri) {
        a->r = merge(a->r, b);
        // pa[a->r->key] = a->key;
        // printf("a:%d pa[a]:%d\n",a->key,pa[a->key]);
        return a;
    } else {
        b->l = merge(b->l, a);
        // pa[b->l->key] = b->key;
        // printf("b:%d pa[b]:%d\n",b->key,pa[b->key]);
        return b;
    }
}
void split(Node *t, Node* &a, Node* &b, int k) {
    if (!t) a = b = 0;
    else if (t->key <= k) {
        a = t;
        split(t->r, a->r, b, k);
    } else {
        b = t;
        split(t->l, a, b->l, k);
    }
}
void dfs(Node* nd) {
    cout<<endl<<"nd:"<<nd->key<<endl;
    if (nd->l) {
        cout<<"l:"<<nd->l->key<<endl;
        pa[nd->l->key] = nd->key;
        dfs(nd->l);
    }
    if (nd->r) {
        cout<<"r:"<<nd->r->key<<endl;
        pa[nd->r->key] = nd->key;
        dfs(nd->r);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    int n,x;
    cin>>n;
    Node* root = 0;
    for (int i=1; i<=n; i++) {
        cin>>x;
        Node *a, *b;
        split(root, a, b, x);
        root = merge(merge(a, new Node(x)), b);
        cout<<"\n\n----"<<x<<endl;
        dfs(root);
    }
    dfs(root);
    for (int i=1; i<=n; i++) cout<<pa[i]<<endl;

    return 0;
}