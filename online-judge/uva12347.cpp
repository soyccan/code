// uva12347
// BST
#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node *l, *r;
    int v;
    Node(int v=0): l(0),r(0),v(v) {}
};
void insert(Node* nd, int v) {
    if (v < nd->v) {
        if (nd->l) insert(nd->l, v);
        else nd->l = new Node(v);
    } else {
        if (nd->r) insert(nd->r, v);
        else nd->r = new Node(v);
    }
}
void dfs(Node* nd) {
    if (!nd) return;
    dfs(nd->l);
    dfs(nd->r);
    cout<<nd->v<<'\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    Node root;
    cin>>root.v;
    while (cin>>x) insert(&root,x);
    dfs(&root);
    return 0;
}
