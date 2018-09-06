#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+5;
struct node{
   int pos, v, next;
}temp, a[MAXN];

vector< node >v, ans ;

int N, L, K;

int main(){
   cin >> L >> N >> K;
   for(int i = 0; i < N; i++){
      scanf("%d %d %d", &temp.pos, &temp.v, &temp.next);
      a[temp.pos] = temp;
   }
   while(L != -1){
      v.push_back( a[L] );
      L = a[L].next;
   }
   int k = v.size() / K;
   for(int i = 0; i < k; i++)
      for(int j = K*(i+1)-1; j >= K*i; j--)
         ans.push_back( v[j] );
   for(int i = k*K; i < v.size(); i++) ans.push_back( v[i] );

   for(int i = 0; i < ans.size(); i++)
      if(i != ans.size() - 1 ) printf("%05d %d %05d\n", ans[i].pos, ans[i].v, ans[i+1].pos);
      else printf("%05d %d -1\n", ans[i].pos, ans[i].v);
   return 0;
}