#include<bits/stdc++.h>
using namespace std;

int main(){
   int NG, NP;
   cin >> NG >> NP;
   queue< int > Q;
   vector< int > v(NG), Rank(NG);
   for(int i = 0; i < NG; i++) scanf("%d", &v[i]);
   for(int i = 0; i < NG; i++) {
      int x;
      scanf("%d", &x);
      Q.push(x);
   }
   while( !Q.empty() ){
      int Size = Q.size();
      int k = 1+ceil( Size*1.0/NP );
      while( Size ){
      	 int maxn = -1, index;
         for(int i = 0; i < NP && Size > 0; i++, Size--){
            int t = Q.front(); Q.pop();
            Rank[t] = k;
            if( v[t] > maxn ) maxn = v[ index = t ];
         }
         Q.push( index );
      } 
	  if( Q.size() == 1 ) {
	     Rank[ Q.front() ] = 1;
		 break;
      }  
   }
   for(int i = 0; i < NG; i++)
      printf("%d%c", Rank[i], (i == NG-1 ? '\n' : ' ') );
   return 0;
}