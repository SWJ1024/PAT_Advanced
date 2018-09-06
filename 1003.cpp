#include<bits/stdc++.h>
using namespace std;

const int maxn = 500+5, inf = 9999999;
int d[maxn][maxn];
int weight[maxn];
int dist[maxn];
int road[maxn];
int peo[maxn];
bool v[maxn];
int N, M, C1, C2;

int main(){
   cin >> N >> M >> C1 >> C2;
   for(int i = 0; i < N; i++) scanf("%d", &weight[i]);
   for(int i = 0; i < M; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      d[b][a] = d[a][b] = c;
   }
   fill(dist, dist+maxn, inf);
   fill(v, v+maxn, false);
   dist[C1] = 0;
   peo[C1] = weight[C1];
   road[C1] = 1;
   for(int k = 0; k < N; k++){
      int u = -1, maxc = inf;
      for(int i = 0; i < N; i++){
         if(!v[i] && dist[i] < maxc) maxc = dist[u = i];
      }
      if(u == -1) break;
      v[u] = true;
      for(int i = 0; i < N; i++){
         int dis = d[u][i];
         if(v[i] || !dis) continue;
         if(dist[i] > dist[u] + dis){
            dist[i] = dist[u] + dis;
            peo[i] = peo[u] + weight[i];
            road[i] = road[u];
         }
         else if(dist[i] == dist[u] + dis){
            peo[i] = max(peo[i], weight[i] + peo[u]);
            road[i] += road[u];
         }
      }
   }
   cout<<road[C2]<<" "<<peo[C2]<<endl;
   return 0;
}