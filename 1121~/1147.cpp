#include<bits/stdc++.h>
using namespace std;

int m, n;
vector< int > v;

bool check(int i , int flag){
  int j = 2 * i;
  if( j > n ) return true;
  if( flag ){
    if( v[j] < v[i] ) return false;
    if( ++j <= n && v[j] < v[i] ) return false;
  }
  else{
    if( v[j] > v[i] ) return false;
    if( ++j <= n && v[j] > v[i] ) return false;
  }
  return check(2*i, flag) && check(2*i+1, flag);
}

void postOrder(int index) {
    if (index > n) return;
    postOrder(index*2);
    postOrder(index*2+1);
    printf("%d%s", v[index], index == 1 ? "\n" : " ");
}

int main() {
    cin >> m >> n;
    v.resize(n+1);
    while( m-- ){
       for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
       if( check(1, 0) ) printf("Max Heap\n");
       else if( check(1, 1) ) printf("Min Heap\n");
       else printf("Not Heap\n");
       postOrder(1);
    }
    return 0;
}