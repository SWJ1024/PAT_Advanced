#include<bits/stdc++.h>
using namespace std;


int main(){
   int N, x;
   set< int > hash;
   cin >> N; 
   while( N-- ){
   	  scanf("%d", &x);
   	  if( x > 0) hash.insert(x);
   }
   int i = 1;
   for(auto it = hash.begin(); it != hash.end(); it++, i++)  if(*it != i){
      break;
   }
   cout << i << endl;
   return 0;
}