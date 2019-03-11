#include <bits/stdc++.h>
using namespace std;
vector< int > pre, in ,post;
int k;

void postOrder(int prel, int inl, int inr) {
    if (inl > inr ) return;
    int i = inl;
    while (in[i] != pre[prel]) i++;
    post[--k] = in[i];
    postOrder(prel+i-inl+1, i+1, inr);
    postOrder(prel+1, inl, i-1);
}

int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    post.resize( k = n );
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    postOrder(0, 0, n-1);
    cout<<post[0];
    return 0;
}