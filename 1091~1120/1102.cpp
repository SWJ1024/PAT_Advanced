#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
vector< vector<int> > v;
int T = 0, N;

void levelorder(){
   int cnt = 0;
   queue< int > Q;
   Q.push(T);
   while( !Q.empty() ){
      int Size = Q.size();
      while( Size-- ){
         int t = Q.front();
         Q.pop();
         cout << t;
         if( ++cnt != N ) cout << " ";
         for(int i = 1; i >= 0; i--) if( v[t][i] != -1) Q.push( v[t][i] );
      }
   }
   cout << endl;
   return;
}

void inorder(int i){
   if( v[i][1] != -1 ) inorder( v[i][1] );
   cout << i;
   if(--N != 0) cout << " ";
   if( v[i][0] != -1 ) inorder( v[i][0] );
}

int main(){
   cin >> N;
   v.resize( N );
   vector< int > node(N, 0);
   for(int i = 0; i < N; i++){
      string s1, s2;
      cin >> s1 >> s2;
      v[i].push_back( s1[0] == '-' ? -1 : ( node [ stoi(s1) ] = 1, stoi(s1) ) );
      v[i].push_back( s2[0] == '-' ? -1 : ( node [ stoi(s2) ] = 1, stoi(s2) ) );
   }
   while( node[T] ) T++;
   levelorder();
   inorder(T);
   return 0;
}