#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e2+10;

int N, M, Q;
bool d[MAXN][MAXN];

int main(){
   cin >> N >> M;
   while( M-- ){
      int x, y;
      scanf("%d%d", &x, &y);
      d[y][x] = d[x][y] = true;
   }
   cin >> Q;
   while( Q-- ){
      int n;
      bool ok = true;
      scanf("%d", &n);
      vector< int > v(n);
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      if( n != N+1 || v[0] != v[n-1]) ok = false;
      else{
         vector< int > temp = v;
         temp.resize(N);
         sort(temp.begin(), temp.end() );
         for(int i = 0; i < N; i++) if( temp[i] != i+1){
            ok = false; break;
         }
         if(ok){
            for(int i = 0; i < N; i++) if( !d[ v[i] ][ v[i+1] ]  ){
               ok = false; break;
            }
         }
      }
      if( ok ) printf("YES\n");
      else printf("NO\n");
   }
   return 0;
}