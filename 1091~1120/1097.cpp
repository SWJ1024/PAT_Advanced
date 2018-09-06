#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;
int T, N;


struct node{
   int add, key, next;
}a[MAXN];


int main(){
   cin >> T >> N;
   for( int i = 0; i< N; i++){
      node t;
      scanf("%d%d%d", &t.add, &t.key, &t.next);
      a[ t.add ] = t;
   }

   int p = T;
   vector< node > v;
   while( p != -1){
      v.push_back( a[p] );
      p = a[p].next;
   }

   unordered_set< int > Myset;
   vector< node > v1, v2;
   for(auto &i : v){
      if( Myset.count( abs(i.key) ) )   v2.push_back( i );
      else {
         v1.push_back( i );
         Myset.insert( abs(i.key) );
      }
   }
   for(int i = 0; i < v1.size(); i++){
      if(i != v1.size()-1 ) printf("%05d %d %05d\n", v1[i].add, v1[i].key, v1[i+1].add);
      else printf("%05d %d -1\n", v1[i].add, v1[i].key);
   }

   for(int i = 0; i < v2.size(); i++){
      if(i != v2.size()-1 ) printf("%05d %d %05d\n", v2[i].add, v2[i].key, v2[i+1].add);
      else printf("%05d %d -1\n", v2[i].add, v2[i].key);
   }

   return 0;
}