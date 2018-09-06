#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
struct node{
  int Address, Data, Next;
}a[MAXN];

int T, N, K;
vector< node > v[3], ans;

int main(){
   cin >> T >> N >> K;
   for(int i = 0; i < N; i++){
      node temp;
      scanf("%d%d%d", &temp.Address, &temp.Data, &temp.Next);
      a[ temp.Address ] = temp;
   }  
   int p = T;
   while( p != -1 ){
      if( a[p].Data < 0) v[0].push_back( a[p] );
      else if( a[p].Data <= K) v[1].push_back( a[p] );
      else v[2].push_back( a[p] );
      p = a[p].Next;
   }
   for(int i = 0; i < 3; i++)
      for(auto &j : v[i])
         ans.push_back(j);
   N = ans.size();
   for(int i = 0; i < N; i++){
      if(i != N-1) printf("%05d %d %05d\n", ans[i].Address, ans[i].Data, ans[i+1].Address);
      else printf("%05d %d -1\n", ans[i].Address, ans[i].Data);
   }
   return 0;
}
