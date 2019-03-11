#include<bits/stdc++.h>
using namespace std;

int main() {
   int N, M;
   scanf("%d%d", &N, &M);
   unordered_map<int, vector<int> > m;
   while (N--) {
      int x, y;
      scanf("%d%d", &x, &y);
      m[x].push_back(y);
      m[y].push_back(x);
   }

   while (M--) {
      int n, x;
      bool ok = true;
      set<int> S;
      scanf("%d", &n);
      while (n--) {
         scanf("%d", &x);
         if (!ok) continue;
         if (S.count(x))	ok = false; 
         else S.insert(m[x].begin(), m[x].end());
      }
     if (ok) printf("Yes\n");
     else printf("No\n");
   }
   return 0;
}