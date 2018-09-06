#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;

int k[MAXN];

int main(){
    int n, m, t, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)  scanf("%d", &k[i]);
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int mid = (n+m+1) / 2, i = 1;
    bool ok = false;
    while( m-- ) {
        scanf("%d", &t);
        while ( k[i] < t) {
            if (++cnt == mid) { cout << k[i]; ok = true; break; }
            i++;
        }
        if (++cnt == mid) { cout << t; ok = true; break; }
    }
    while (!ok && i <= n) {
        if (++cnt == mid) { cout << k[i]; break; }
        i++;
    }
    return 0;
}