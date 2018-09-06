#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+50, INF = 99999999;
int N, M, K, D, n;
int d[MAXN][MAXN];
bool v[MAXN];
int dist[MAXN];
int MinDist = 0, DistSum = INF, Indix = INF;

int getid( char *p ){
   if( p[0] != 'G' ) return atoi(p);
   else return atoi(p+1)+N;
}

int main() {
    cin >> N >> M >> K >> D;
    n = N+M;
    while( K-- ){
       int P1, P2, Dist;
       char p1[10], p2[10];
       scanf("%s%s%d", p1, p2, &Dist);
       P1 = getid( p1 );
       P2 = getid( p2 );
       d[P2][P1] = d[P1][P2] = Dist;
	}
    
    for(int i = N+1; i <= n; i++){
       for(int j = 1; j <= n; j++) dist[j] = j == i ? 0 : INF;
       fill(v, v+MAXN, false);
       for(int t = 1; t <= n; t++){
          int x = -1, minn = INF;
          for(int y = 1; y <= n; y++) if( !v[y] && dist[y] < minn)
             minn = dist[x = y];
          if( x == -1 ) break;
          v[x] = true;
          for(int y = 1; y <= n; y++) if( !v[y] && d[x][y])
             dist[y] = min( dist[y], dist[x]+d[x][y] );
      }
    
       int TempMinDist = INF, TempDistSum = 0;
       bool ok = true;
       for(int i = 1; i <= N; i++){ 
          if( dist[i] > D) { ok = false;  break; }
          TempMinDist = min( TempMinDist, dist[i] );
          TempDistSum += dist[i];
       }
     
       if(ok && ( MinDist < TempMinDist || ( MinDist == TempMinDist && TempDistSum < DistSum ) ) ){ 
          DistSum = TempDistSum;
          MinDist = TempMinDist; 
          Indix = i;
       }
    }
    
    if( Indix == INF) printf("No Solution\n");
    else  printf("G%d\n%.1f %.1f\n", Indix-N, (double)MinDist, (double)DistSum/N);
    return 0;
}