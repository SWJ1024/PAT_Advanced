#include<bits/stdc++.h>
using namespace std;

const int maxn = 500+5, inf = 9999999;
int N, M, S, D;
int d[maxn][maxn], w[maxn][maxn];
int dis[maxn], cost[maxn], v[maxn], fa[maxn];

int main(){
   cin >> N >> M >> S >> D;
   while( M-- ){
      int City1, City2, Distance, Cost;
      scanf("%d%d%d%d",&City1, &City2, &Distance, &Cost);
      d[City1][City2] = d[City2][City1] = Distance;
      w[City1][City2] = w[City2][City1] = Cost;
   }
   for(int i = 0; i < N; i++) dis[i] = (i == S ? 0 : inf);
   for(int i = 0; i < N; i++){
      int x = -1, m = inf;
      for(int y = 0; y < N ; y++) if(!v[y] && dis[y] < m) m = dis[x = y];
      if(x == -1) break;
      v[x] = 1;
      for(int y = 0; y < N; y++) if(!v[y] && d[x][y]){
        if( dis[y] > dis[x] + d[x][y] || ( dis[y] == dis[x] + d[x][y]  && cost[y] > cost[x] + w[x][y]) ){
            dis[y] = dis[x] + d[x][y];
            cost[y] = cost[x] + w[x][y];
            fa[y] = x;
         }
      }
   }
   vector< int > temp;
   for(int i = D;; i = fa[i]){
      temp.push_back(i);
      if(i == S) break;
   }
   for(int i = temp.size()-1; i >= 0; i--) cout << temp[i] << " " ;
   cout << dis[D] << " " << cost[D] << endl;
   return 0;
}