#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int [n], *b = new int [n];
    for (int i = 0; i < n; i++)  scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)  scanf("%d", &b[i]);
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; j < n && a[j] == b[j]; j++);
    if ( j == n ) {
        printf("Insertion Sort\n");
        sort(a, a+i+2);
    } else {
        printf("Merge Sort\n");
        int k = 1;
		bool ok = false;
        while( !ok ) {
            ok = true;
            for (i = 0; i < n; i++) if( a[i] != b[i] )
               ok = false;
            k *= 2;
            for (i = 0; i < n/k; i++)  sort( a+i*k, a+(i+1)*k );
            sort( a+n/k*k, a+n );
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i == n-1 ? '\n' : ' ') );
    delete [] a;   delete [] b;
    return 0;
}