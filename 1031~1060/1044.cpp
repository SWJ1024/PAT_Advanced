#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10, inf = 99999999;
int a[maxn];
int N, S, p, q, sum, minS = inf;;
bool ok = false;

void simulation(int S){
   p = q = 1; sum = 0;
   while(q <= N){
      sum += a[q];
      if(sum > S) {
          minS = min(minS, sum);
          sum -= a[ p++ ]+a[ q-- ];
      }
      else if(sum == S){
         printf("%d-%d\n", p, q);
         sum -= a[p++];
         ok = true;
      }
      q++;
   }
}

int main(){
   cin >> N >> S;
   for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
   simulation( S );
   if(!ok) simulation( minS );
   return 0;
}