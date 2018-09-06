#include <bits/stdc++.h>
using namespace std;

map<int, bool> Mymap;

int main() {
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        Mymap[ pre[i] ] = true;
    }
    while( m-- ){
        scanf("%d %d", &u, &v);
        for(auto &i : pre) {
            a = i;
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        } 
        if (Mymap[u] == false && Mymap[v] == false)  printf("ERROR: %d and %d are not found.\n", u, v);
        else if (Mymap[u] == false || Mymap[v] == false)  printf("ERROR: %d is not found.\n", Mymap[u] == false ? u : v);
        else if (a == u || a == v)  printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else  printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}