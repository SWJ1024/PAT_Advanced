#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505, INF = 99999999;
int d[2][MAXN][MAXN];
int dist[2][MAXN], v[MAXN], path[MAXN];
int City[MAXN], T[MAXN];
int N, M, C, S;
vector< int > ans[2];

void Dijkstra( int k ){
   dist[k][C] = 0;
   memset(v, 0, sizeof(v));
   memset(City, 0, sizeof(City));
   memset(T, 0, sizeof(T));
   for(int i = 0; i < N; i++){
      int minn = INF, x = -1;
      for(int y = 0; y < N; y++) if( !v[y] && dist[k][y] < minn){
         minn = dist[k][ x = y];
      }
      if( x < 0) break;
      v[x] = 1;
      for(int y = 0; y < N; y++) if( !v[y] && d[k][x][y] ){
         if(dist[k][y] > dist[k][x] + d[k][x][y]){
            dist[k][y] = dist[k][x] + d[k][x][y];
            path[y] = x;
            City[y] = City[x]+1;
            T[y] = T[x]+d[1][x][y];
         }
         else if(dist[k][y] == dist[k][x] + d[k][x][y]){
            if( (!k && T[y] > T[x]+d[1][x][y] ) || ( k && City[y] > City[x]+1) ){
               path[y] = x;
               T[y] = T[x]+d[1][x][y];
               City[y] = City[x]+1;
            }
         }
      }
   }
}

void print( int k ){
   vector< int > &v = ans[k];
   for(int i = v.size()-1; i >= 0; i--){
        cout << v[i];
        if( i ) cout << " -> ";
        else cout << endl;
   }
   return ;
}

int main(){
   cin >> N >> M;
   while( M-- ){
      int V1, V2, one_way, length, Time;
      scanf("%d%d%d%d%d", &V1, &V2, &one_way, &length, &Time);
      d[0][ V1 ][ V2 ] = length;
      d[1][ V1 ][ V2 ] = Time;
      if( !one_way ) {
         d[0][ V2 ][ V1 ] = length;
         d[1][ V2 ][ V1 ] = Time;
      }
   }
   scanf("%d%d", &C, &S);
   fill(dist[0], dist[0]+2*MAXN, INF);
   for(int k = 0; k < 2; k++){
      Dijkstra( k );
      for(int i = S; i != C; i = path[i]) ans[k].push_back(i);
      ans[k].push_back(C);
   }
   if( ans[0] == ans[1] ){
       printf("Distance = %d; Time = %d: ", dist[0][S], dist[1][S]);
       print(0);
   }
   else{
       printf("Distance = %d: ", dist[0][S]);  print(0);
       printf("Time = %d: ", dist[1][S]);  print(1);
   }
   return 0;
}