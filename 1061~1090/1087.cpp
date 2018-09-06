#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200+5, inf = 9999999;
int N, M, S, cnt = 0;
char city[4], city2[4];
map< int, int > IDCache, NameCache;
int w[MAXN];
int d[MAXN][MAXN];
int dist[MAXN], road[MAXN], happy[MAXN], citysum[MAXN], path[MAXN];
int v[MAXN];

int getid(char *s)  {
   int id  = (s[0]-'A')*26*26 +(s[1]-'A')*26 +(s[2]-'A');
   if( !NameCache.count( id ) ){
      NameCache[ id ] = cnt;
      IDCache[ cnt++ ] = id;
   }
   return NameCache[ id ];
}

void getname(int i){
     int id = IDCache[i];
     cout << char(id/26/26+'A') << char( (id/26)%26+'A' ) << char( id%26+'A' );
}

void init(){
   cin >> N >> M >> city;
   S = getid( city );
   for(int i = 0; i < N-1; i++){
      int happiness;
      scanf("%s%d", city, &happiness);
      int id = getid( city );
      w[ id ] = happiness;
   }
}

int main(){
   init();
   for(int i = 0; i < M; i++){
      int distance;
      scanf("%s%s%d",city, city2, &distance);
      int a = getid(city), b = getid(city2);
      d[a][b] = d[b][a] = distance;
   }

   fill(dist, dist+MAXN, inf);
   dist[ S ] = 0;
   road[ S ] = 1;
   path[ S ] = -1;
   for(int i = 0; i < N; i++){
      int minn = inf, x = -1;
      for(int y = 0; y < N; y++) if(!v[y] && dist[y] < minn){
         minn = dist[ x = y];
      }
      if( x < 0) break;
      v[x] = 1;
      for(int y = 0; y < N; y++) if(!v[y] && d[x][y]){
          if( dist[y] > dist[x] + d[x][y]){
             dist[y] = dist[x] + d[x][y];
             road[y] = road[x];
             happy[y] = happy[x] + w[y];
             citysum[y] = citysum[x]+1;
             path[y] = x;
          }
          else if(dist[y] == dist[x] + d[x][y]){
             road[y] += road[x];
             if(happy[y] < happy[x]+w[y] || (happy[y] == happy[x]+w[y] && citysum[y] > citysum[x]+1) ){
                 happy[y] = happy[x]+w[y];
                 citysum[y] = citysum[x]+1;
                 path[y] = x;
             }
          }
      }
   }
   memcpy(city, "ROM", sizeof(city));
   int c = getid(city);
   vector< int > ans;
   for(int i = c; i != -1; i = path[i]) ans.push_back(i);
   cout << road[c] << " " << dist[c] << " " << happy[c] << " " << happy[c]/citysum[c] << endl;
   for(int i = (int)ans.size()-1; i >= 0; i--){
      getname( ans[i] );
      if(i) cout << "->";
   }
   return 0;
}