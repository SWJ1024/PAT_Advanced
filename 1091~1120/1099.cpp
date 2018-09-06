#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;
int N, Left, Right;
int A[MAXN][2], cnt;
vector< int > pre, level, v;

void preorder(int i){
   if( A[i][0] != -1) preorder( A[i][0] );
   pre[ i ] = cnt++;
   if( A[i][1] != -1) preorder( A[i][1] );
   return;
}

void levelorder(){
   cnt = 0;
   queue< int > Q;
   Q.push( 0 );
   while( !Q.empty() ){
       int Size = Q.size();
       while( Size-- ){
          int i = Q.front();
          Q.pop();
          level[ cnt++ ] = i;
          if( A[i][0] != -1) Q.push( A[i][0] );
          if( A[i][1] != -1) Q.push( A[i][1] );
       }
   }
   return;
}



int main(){
   cin >> N;
   pre.resize( N );
   level.resize( N );
   v.resize(N);
   for(int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1];
   cnt = 0;
   preorder( 0 );
   levelorder();
   for(int i = 0; i < N; i++) cin >> v[i];
   sort( v.begin(), v.end() );
   for(int i = 0; i < N; i++) {
      if( i ) putchar(' ');
      cout <<  v[ pre[ level[i] ] ];
   }
   return 0;
}