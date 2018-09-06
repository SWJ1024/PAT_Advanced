#include<bits/stdc++.h>
using namespace std;

int N, head, cnt;
double r, p;
vector< vector< int > >v;
double maxsum = -1; 

void dfs(int i, double p){
   if( v[i].empty() ){
      if(p > maxsum) { maxsum = p; cnt = 1; }
      else if( abs(p-maxsum) < 1e-5 ) cnt++;
   }
   else for(auto &j : v[i])  dfs(j, p*r);
}

int main(){
   cin >> N >> p >> r;
   v.resize(N);
   r = r/100+1;
   for(int i = 0; i < N; i++){
      int x;
      scanf("%d", &x);
      if( x == -1) head = i;
      else v[x].push_back(i);
   }
   
   dfs(head, p);
   
   printf("%.2f %d\n", maxsum, cnt);
   return 0;
}