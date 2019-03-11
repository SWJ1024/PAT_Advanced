#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500+5;
int N, M;

vector< int > degree;
bool d[MAXN][MAXN];
bool v[MAXN];

void dfs(int i){
   v[i] = true;
   for(int j = 0; j < N; j++) if( !v[j] && d[i][j])
      dfs(j);
}

int main(){
   cin >> N >> M;
   degree.resize(N);
   for(int i = 0; i < M; i++){
      int x, y;
      scanf("%d%d", &x, &y);
      degree[--x]++; degree[--y]++;
      d[x][y] = d[y][x] = true;
   }

   bool ok = false;;
   for(int i = 0; i < N; i++) if( !v[i] ){
      if( !ok ) ok = true;
      else { ok = false; break; }
      dfs(i);
   }
   
   int cnt = 0;
   for(int i = 0; i < N; i++){
      printf("%d%c", degree[i], (i == N-1) ? '\n' : ' ');
      if( degree[i] % 2 ) cnt++;
   }
   if( !cnt && ok) printf("Eulerian\n");
   else if( cnt == 2 && ok) printf("Semi-Eulerian\n");
   else printf("Non-Eulerian\n");
   return 0;
}