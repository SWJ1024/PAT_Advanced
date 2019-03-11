#include<bits/stdc++.h>
using namespace std;

bool isprime( int n ){
   if( n <= 1 )  return false;
   for(int i = 2; i <= sqrt(n)+0.5; i++){
      if( n % i == 0) return false;
   }
   return true;
}

int main(){
   int N, M, Q, x;
   cin >> N >> M >> Q;
   while( !isprime(N) ) N++;
   vector< int > hash(N);
   while( M-- ){
      bool ok = false;
      scanf("%d", &x);
      for(int j = 0; j < N; j++) if( !hash[ (x+j*j)%N ] ) {
          hash[ (x+j*j)%N ] = x;
          ok = true;
	  break;
      }
      if( !ok ) printf("%d cannot be inserted.\n", x);
   }
   int cnt = 0;
   for(int i = 0; i < Q; i++){
      scanf("%d", &x);
      for(int j = 0; j <= N; j++){
         int v = hash[ (x+j*j)%N ];
         cnt++;
         if( !v || v == x)  break;
      }
   }
   printf("%.1f\n", cnt*1.0/Q);
   return 0;
}
