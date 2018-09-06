#include<bits/stdc++.h>
using namespace std;


int main(){
   int N, n, sum = 0, x;
   cin >> N;
   n = N/2;
   vector< int > v(N+1);
   for(int i = 1; i <= N; i++) scanf("%d", &v[i]);
   sort( v.begin()+1, v.end() );
   for(int i = 1; i <= N; i++){
	  if( i <= n) sum -= v[i];
   	  else sum += v[i];
   }
   printf("%d %d\n", N%2, sum);
   return 0;
}