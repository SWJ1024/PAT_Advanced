#include<bits/stdc++.h>
using namespace std;


const int maxn = 500+5, inf = 999999;
int d[maxn][maxn], w[maxn], v[maxn], dis[maxn];
vector< vector< int > > path, p;
vector<int> temp, ans;
int Cmax, N, S, M, perfect, bestneed = inf, bestleft = inf;

void init(){
   cin >> Cmax >> N >> S >> M;
   perfect = Cmax/2;
   path.resize(N+1);
   p.resize(N+1);
   for(int i = 1; i <= N; i++) scanf("%d", &w[i]);
   while(M--){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      d[b][a] = d[a][b] = c;
   }
}

void Dijkstra(){
   for(int i = 1; i <= N; i++) dis[i] = inf;
   for(int i = 0; i <= N; i++){
      int x = -1, m = inf;
      for(int y = 0; y <= N; y++) if(!v[y] && dis[y] < m) m = dis[ x = y ];
      if(x == -1) break;
      v[x] = 1;
      for(int y = 0; y <= N; y++) if(!v[y] && d[x][y]){
         if(dis[y] > dis[x] + d[x][y]){
            dis[y] = dis[x] + d[x][y];
            path[y].clear();
            path[y].push_back(x);
         }
         else if(dis[y] == dis[x] + d[x][y])
            path[y].push_back(x);
      }
   }
}

void getroad(){
   for(int i = 0; i <= N; i++)
      for(int j = 0; j < path[i].size(); j++)
          p[ path[i][j] ].push_back(i);
}

void dfs(int i, int Need, int Left){
   temp.push_back(i);
   int Size = p[i].size();
   if( i ){
      if( w[i] < perfect ){
          if( Left >= perfect-w[i] )	 Left -= perfect-w[i];
         else {
             Need += perfect-w[i]-Left;
             Left = 0;
         }
      } 
      else Left += w[i]-perfect;
   }
   if( i == S && ( ans.empty() ||  Need < bestneed || ( Need == bestneed && Left < bestleft ) ) ){
       ans = temp;
       bestneed = Need;
       bestleft = Left;
   }
   else for(int j = 0; j < Size; j++){
       int k = p[i][j];
       dfs(k, Need, Left);
       temp.pop_back();
   }
}

void print(){
   cout<< bestneed <<' ';
   for(int i = 0; i < ans.size(); i++){
        if(i) cout << "->";
        cout << ans[i];
   }
   cout << " " << bestleft << endl;
}

int main(){
   init();
   Dijkstra();
   getroad();
   dfs(0, 0, 0);
   print();
   return 0;
}