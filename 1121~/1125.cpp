#include<bits/stdc++.h>
using namespace std;


int main(){
   int N;
   cin >> N;
   vector< int > v(N);
   for(int i = 0; i < N; i++)
      scanf("%d", &v[i]);
   sort( v.begin(), v.end() );
   double sum = v[0];
   for(int i = 1; i < N; i++)
      sum = (sum + v[i]) / 2;
   printf("%d\n", (int)floor(sum) );
   return 0;
}