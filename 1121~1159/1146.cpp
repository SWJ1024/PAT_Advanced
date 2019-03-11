#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > v, u;
vector< int > Degree, degree;

int main(){
   int N, M, Q, x, y;
   cin >> N >> M;
   v.resize( N+1 );
   Degree.resize( N+1 );
   while( M-- ){
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      Degree[y]++; 
   }
   
   cin >> Q;
   vector< int > Ans;
   for(int k = 0; k < Q; k++){
      degree = Degree; u = v;
      bool ok = true;
      for(int i = 0; i < N; i++){
         scanf("%d", &x);
         if( degree[x] ) ok = false;
         if( !ok ) continue;
         for(int j = 0; j < u[x].size(); j++)
            degree[ u[x][j] ]--;
      }
      if( !ok ) Ans.push_back(k);
   }
   for(int i = 0; i < Ans.size(); i++)
      printf("%d%c", Ans[i], ( i == Ans.size()-1 ? '\n' : ' ') );
   
   return 0;
}
