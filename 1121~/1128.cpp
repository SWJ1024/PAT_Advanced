#include<bits/stdc++.h>
using namespace std;

int main(){
   int N, M, x;
   cin >> N;
   while( N-- ){
      bool ok = true;
      cin >> M;
      vector< bool > v(M+1, false), v1(2*M+1, false), v2(2*M+1, false);
      for(int i = 0; i < M; i++){
         scanf("%d", &x);
         if( !ok ) continue;
         if(  v[x] || v1[x+M-i] || v2[x+i] ) ok = false;
         else  v[x] = v1[x+M-i] = v2[x+i] = true;
      }
      printf("%s\n", ok ? "YES" : "NO" );
   }
   return 0;
}