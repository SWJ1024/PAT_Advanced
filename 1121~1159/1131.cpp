#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+10, INF = 9999999;

int M, Q, S, D, n = 0;
int d[MAXN][MAXN];
int dist[MAXN], path[MAXN], road[MAXN], line[MAXN];
bool v[MAXN];

map<int, int> IDcache, CityCache;

int getid(int city){
   if( !IDcache.count(city) ){
      IDcache[city] = n;
      CityCache[n++] = city;
   }
   return IDcache[city];
}

void print(){
   printf("%d\n", dist[D]);
   vector< int > ans;
   int preline = -1;
   for(int i = D; i != S; i = path[i]) if(line[i] != preline ){
      ans.push_back( i );
      preline = line[i];
   }
   ans.push_back( S );
   for(int i = ans.size()-1; i > 0; i--)
      printf("Take Line#%d from %04d to %04d.\n", line[ ans[i-1] ] , CityCache[ ans[i] ], CityCache[ ans[i-1] ] );
}

void Dijkstra(){
   fill(dist, dist+MAXN, INF);
   memset(v, false, sizeof(v) );
   memset(road, 0, sizeof(road));
   memset(line, 0, sizeof(line));
   dist[S] = 0;
   for(int i = 0; i < n; i++){
      int x = -1, minn = INF;
      for(int y = 0; y < n; y++) if( !v[y] && dist[y] < minn){
         minn = dist[ x = y];
      }
      if( x < 0 ) break;
      v[x] = true;
      for(int y = 0; y < n; y++) if( !v[y] && d[x][y]){
         if(dist[y] > dist[x] + 1){
            dist[y] = dist[x] + 1;
            road[y] = (d[x][y] == line[x]) ? road[x] : road[x]+1;
            line[y] = d[x][y];
            path[y] = x;
         }
         else if(dist[y] == dist[x] + 1 && road[y] > ( (d[x][y] == line[x]) ? road[x] : road[x]+1) ){
            road[y] = d[x][y] == line[x] ? road[x] : road[x] + 1;
            line[y] = d[x][y];
            path[y] = x;
         }
      }
   }
   print();
}

int main(){
   cin >> M;
   for(int i = 1; i <= M; i++){
      int N, id, x, y;
      scanf("%d%d", &N, &id);
      x = getid( id );
      while( --N ){
         scanf("%d", &id);
         y = getid( id );
         d[x][y] = d[y][x] = i;
         x = y;
      }
   }
   cin >> Q;
   while( Q-- ){
      scanf("%d%d", &S, &D);
      S = getid(S);
      D = getid(D);
      Dijkstra();
   }
   return 0;
}
