#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000+10;
int N, M, K;
vector<vector<int> >v;
bool visit[maxn];

void dfs(int i){
  visit[i] = true;
   for(int &j : v[i]) if(!visit[j]) 
      dfs( j );
}

int main(){
   cin >> N >> M >> K;
   v.resize(N+1);
   int a, b;
   for(int i = 0; i < M; i++){
       scanf("%d%d",&a, &b);
       v[a].push_back(b);  v[b].push_back(a);
   }

   while(K--){
      memset(visit, false, sizeof(visit));
      int cnt = 0, c;
      cin >> c;
      visit[c] = true;
      for(int i = 1; i <= N; i++) if(!visit[i]) {
          dfs( i ); cnt++;
      }
      cout << cnt-1 << endl;
   }
   return 0;
}