#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;
int fa[MAXN], MAX = 1;
unordered_set< int >  Set;


int findfa( int x){
   return x == fa[x] ? x : (fa[x] = findfa(fa[x]) );
}

int main(){
   int N, Q;
   cin >> N;
   for( int i = 0; i < MAXN; i++) fa[i] = i;
   for(int i = 0; i < N; i++){
      int n, x, y;
      scanf("%d %d", &n, &x);
      MAX = max(MAX, x);
      x = findfa(x);
      while( --n ){
         scanf("%d", &y);
         MAX = max(MAX, y);
         y = findfa(y);
         fa[y] = x;
      }
   }
   for(int i = 1; i <= MAX; i++) Set.insert( findfa(i) );
   cin >> Q;
   cout << Set.size() << " " << MAX << endl;
   while( Q-- ){
      int x, y;
      scanf("%d%d", &x,&y);
      if(fa[x] == fa[y] ) cout << "Yes\n";
      else cout << "No\n";
   }
   return 0;
}