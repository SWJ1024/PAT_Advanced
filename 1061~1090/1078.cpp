#include<bits/stdc++.h>

using namespace std;

bool isprime( int n ){
   if( n <= 1 ) return false;
   for(int i = 2; i <= sqrt(n)+0.5; i++){
      if( n % i == 0 ) return false;
   }
   return true;
}

int main(){
   int MSize, N;
   cin >> MSize >> N;
   for(int i = MSize;; i++) if( isprime(i) ){
      MSize = i; break;
   }
   vector< int > v(MSize, -1), p(N, -1);
   int x, k = MSize/2;
   for(int j = 0; j < N; j++){
      scanf("%d", &x);
      for(int i = 0; i <= k; i++) if( v[ (i*i+x)%MSize ] == -1){
          v[ p[j] = (i*i+x)%MSize ] = x;
          break;
      }
   }
   for(int i = 0; i < N; i++){
      if(i) putchar(' ');
      if( p[i] == -1) putchar('-');
      else printf("%d", p[i]);
   }
   return 0;
}