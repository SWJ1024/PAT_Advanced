#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;
int N, M, K;
struct node{
   char name[10];
   int height;
   bool operator < (const node &rhs) const{
      return (height == rhs.height) ? (strcmp(name, rhs.name) < 0) : height > rhs.height;
   }
} a[MAXN];

int main(){
   cin >> N >> K;
   M = N/K;
   for(int i = 0; i < N; i++)
      scanf("%s%d", a[i].name, &a[i].height);
   sort(a, a+N);
   int p = 0, q = N - M*K + M;
   while(q <= N){
      deque< node > Q;
      for(int i = p, k = 1; i < q; i++, k ^= 1){
         if(k) Q.push_back( a[i] );
         else Q.push_front( a[i] );
      }
      int flag = 0;
      while( !Q.empty() ){
         if( flag ) putchar(' ');
         else flag = 1;
         printf("%s", Q.front().name );
         Q.pop_front();
      }
      putchar('\n');
      p = q;
      q = p+M;
   }
   return 0;
}