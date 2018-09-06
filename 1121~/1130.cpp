#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+10;
int N, T = 0;
vector< string > expr;
vector< vector< int > > v;

void dfs( int i ){
   if(i != T && ( v[i][0] != -1 || v[i][1] != -1 ) ) putchar('(');
   if( v[i][0] != -1 ) dfs( v[i][0] );
   cout << expr[i];
   if( v[i][1] != -1 ) dfs( v[i][1] );
   if(i != T && ( v[i][0] != -1 || v[i][1] != -1 ) ) putchar(')');
}

int main(){
   cin >> N;
   vector< int > head(N);
   v.resize(N);
   expr.resize(N);
   for(int i = 0; i < N; i++){
      string a; int x, y;
      cin >> a >> x >> y;
      if( x != -1 ) head[--x]++;
      if( y != -1 ) head[--y]++;
      v[i].push_back(x);
      v[i].push_back(y);
      expr[i] = a;
   }

   while( head[T] ) T++;
   dfs(T);
   return 0;
}