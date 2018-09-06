#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000+5;
double N[maxn];

int main(){
   int T = 2, n, k;
   double a;
   while(T--){
      cin >> n;
      while(n--){
         cin >> k >> a;
         N[k] += a;
      }
   }
   int cnt = 0;
   for(auto i : N)   if(i != 0.0) cnt++;
   cout<<cnt;
   for(int i = maxn-1; i >= 0; i--)
      if(N[i] != 0.0)
         printf(" %d %.1f",i,N[i]);
   return 0;
}