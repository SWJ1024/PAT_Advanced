#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
vector< int > v[MAXN];
int w[MAXN];
double Sum = 0.0,P ,R;

void dfs(int i, double money){
   if( v[i].empty() )   Sum += ( money*w[i] );
   else for(auto &j : v[i])   dfs(j, money*R);
   return;
}


int main(){
   int N, n, x;
   cin >> N >> P >> R;
   R = R/100 + 1;
   for(int i = 0; i < N; i++){
      scanf("%d", &n);
      if( !n )   scanf("%d", &w[i]);
      else while( n-- ){
         scanf("%d", &x);
         v[i].push_back(x);
      }
   }

   dfs(0, P);
   printf("%.1f\n", Sum);
   return 0;
}