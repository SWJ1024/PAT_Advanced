#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;
int G[MAXN][MAXN];
unordered_map<int, int> fa;

int findfa(int x) {
   return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}

bool cmp(const vector<int> &lhs, const vector<int> &rhs) {
   return lhs[0] < rhs[0];
}


int main() {
   int K, N, M;
   cin >> K >> N >> M;
   int a, b, c;
   while (M--) {
      scanf("%d%d%d", &a, &b, &c);
      G[a][b] += c;
   }	
   vector<int> suspect;
   for (int i = 1; i <= N; i++) {
       int cnt = 0, call_back = 0;
       for (int j = 1; j <= N; j++) if (G[i][j] != 0){
            if (G[i][j] <= 5) {
                cnt++;
                if (G[j][i] != 0) call_back++;	
            }
            if (cnt > K && 0.2*cnt >= call_back) suspect.push_back(i);
        }
   }
   if (suspect.empty()) {
        cout << "None\n";
        return 0;
   }
   int sz = suspect.size(); 

   for (int i = 0; i < suspect.size(); i++)   fa[suspect[i]] = suspect[i];
   
   for (int ii = 0; ii < sz; ii++) {
      for (int jj = ii+1; jj < sz; jj++) {
          int i  = suspect[ii], j = suspect[jj];
          if (G[i][j] && G[j][i]) {
             int a = findfa(i);
             int b = findfa(j);
             if (a !=b) fa[a] = b;
          }
       }
   }
   map<int, vector<int> > m;
   for(unordered_map<int, int>::iterator it = fa.begin(); it != fa.end(); it++) {
       int father = findfa(it->second);
       m[father].push_back(it->first);
   }
   vector<vector<int> > res;
   for(map<int, vector<int> >::iterator it = m.begin(); it != m.end(); it++) {
       vector<int> &t = it->second;
       sort(t.begin(), t.end());
       res.push_back(t);
   }
   sort(res.begin(), res.end(), cmp);
   
   for (int i = 0; i < res.size(); i++) {
         vector<int> &t = res[i];
         int sz = t.size();
         for (int j = 0; j < sz; j++) {
         printf("%d%c", t[j], (j == sz-1 ? '\n': ' '));
      }
   }
   return 0;
}


