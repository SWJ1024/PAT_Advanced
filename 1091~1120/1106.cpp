#include<bits/stdc++.h>
using namespace std;

double P, r;
int N, mindeep = 999999, sum;
vector< vector< int > >v;

void dfs(int i, int deep){
   if( v[i].empty() ){
     if( deep < mindeep){
        mindeep = deep;
        sum = 1;
     }
     else if( deep == mindeep) sum++;
     return;
   }
   for(auto &j : v[i]) dfs(j, deep+1);
}

int main(){
   cin >> N >> P >> r;
   r = r/100 + 1;
   v.resize(N);
   for(int i = 0; i < N; i++){
      int n, x;
      scanf("%d", &n);
      while( n-- ){
        scanf("%d", &x);
        v[i].push_back(x);
      }
   }
   dfs(0, 0);
   printf("%.4f %d\n", pow(r, mindeep)*P, sum);
   return 0;
}