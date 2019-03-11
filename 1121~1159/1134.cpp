#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int N, M, K, Q;
vector< vector< int > > v;

int main(){
   cin >> N >> M;
   v.resize( N );
   for(int i = 0; i < M; i++){
      int x, y;
      scanf("%d%d", &x, &y);
      v[x].push_back(i);
      v[y].push_back(i);
   }
   cin >> Q;
   while( Q-- ){
      cin >> K;
      vector< bool > hash(M);
      int cnt = 0;
      bool ok = false;
      for(int i = 0; i < K; i++){
         int x;
         scanf("%d", &x);
         if( ok ) continue;
         for(auto &i : v[x]) if( !hash[i] ){
            hash[i] = true;
            if( ++cnt == M) ok = true;
         }
      }
      if(ok) cout << "Yes\n";
      else cout << "No\n";
   }
   return 0;
}