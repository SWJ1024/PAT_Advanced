#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;
int N, T = 0, LAST;
vector< vector< int > > v;

bool levelorder( int T ){
   queue< int > Q;
   Q.push( T );
   int flag = 1;
   while( !Q.empty() ){
      int Size = Q.size();
      while( Size-- ){
         vector< int > &t = v[ LAST = Q.front() ];
         Q.pop();
         if( t[0] != -1 && t[1] != -1 ){
            if( !flag ) return false;
            Q.push( t[0] ); Q.push( t[1] );
         }
         else if( t[0] != -1){
            if( !flag ) return false;
            Q.push( t[0] );
            flag = 0;
         }
         else if( t[1] != -1)  return false;
         else flag = 0;
      }
   }
   return true;
}

int main(){
   cin >> N;
   v.resize( N );
   vector< int > node(N, 0);
   for(int i = 0; i < N; i++){
       string l, r;
       cin >> l >> r;
       v[i].push_back(  l[0] == '-' ?  -1 : ( node[ stoi(l) ] = 1, stoi(l)  ) );
       v[i].push_back(  r[0] == '-' ?  -1 : ( node[ stoi(r) ] = 1, stoi(r)  ) );
   }
   while( node[T] ) T++;
   if( levelorder( T ) ) printf("YES %d\n", LAST);
   else printf("NO %d\n", T);
   return 0;
}