#include <bits/stdc++.h>
using namespace std;

const int maxc = 20+5, maxn = 1000+10, inf = 999999;
int N, M, K, Q, k;
int servetime[maxn], leveltime[maxn];
struct node{
   int id, first_end_time;
   bool operator < (const node &rhs) const {
      return first_end_time == rhs.first_end_time ? (id > rhs.id) : (first_end_time > rhs.first_end_time);
   }
};

priority_queue< node > window_Q;
queue< int >Win[maxc];

void init(){
   cin >> N >> M >> K >> Q;
   for(int i = 1; i <= K; i++){
       scanf("%d", &servetime[i]);
       leveltime[i] = inf;
   }
   for(k = 1; k <= K && k <= N*M; k++)
       Win[ (k % N) == 0 ? N: ( k%N ) ].push( k );
   for(int i = 1; i <= N; i++) if( !Win[i].empty() )
       window_Q.push( node{i, servetime[ Win[i].front() ] } );
}

void simulation(){
   while( !window_Q.empty() ){
      node u = window_Q.top();
      window_Q.pop();
      int a = Win[u.id].front();
      Win[u.id].pop();
      leveltime[a] = u.first_end_time;
      if(k <= K)   Win[u.id].push( k++ );
      if( !Win[u.id].empty() ){
          u.first_end_time += servetime[Win[u.id].front() ];
          window_Q.push( u );
      }
   }
}

int main(){
  init();
  simulation();
  while(Q--){
     int a;
     scanf("%d", &a);
     if(leveltime[a]-servetime[a] >= 540) cout<<"Sorry\n";
     else printf("%02d:%02d\n", leveltime[a]/60+8, leveltime[a]%60);
  }
  return 0;
}