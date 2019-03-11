#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200+5;
int G[MAXN][MAXN];
int id, short_dist = INT_MAX;

int main() {
   int N, M, Q;
   scanf("%d%d", &N, &M);
   for (int i = 0; i < M; i++) {
       int x, y, dist;
       scanf("%d%d%d", &x, &y, &dist);
       G[x][y] = G[y][x] = dist;
   }
   cin >> Q;
   for (int t = 1; t <= Q; t++) {
      bool simple = true, ok = true;
      vector<bool> v(N+1, false);
      int k, start, pre, cur, dist = 0, cnt = 0;
      scanf("%d%d", &k, &start);
      pre = start;
      for (int i = 1; i < k; i++) {
          scanf("%d", &cur);
          if (!ok) continue;
          if (v[cur]) simple = false;
          else cnt++;
          v[cur] = true;
          if (G[pre][cur] == 0) ok = false;
          else dist += G[pre][cur];
          pre = cur;
      }
      printf("Path %d: ", t);
      if (!ok) cout << "NA";
      else cout << dist;
      if (cnt == N && pre == start) {
         if (dist < short_dist) {
             short_dist = dist;
             id = t;
         }
         if (simple) cout <<  " (TS simple cycle)\n";
         else cout << " (TS cycle)\n";
      }
      else cout << " (Not a TS cycle)\n";
   }
   printf("Shortest Dist(%d) = %d\n", id, short_dist);
   return 0;
}