#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;
vector< vector< int > > v;
bool c[MAXN];
int N, L, Q, cnt, sum;

void bfs(int i){
   cnt = sum = 0;
   fill(c, c+N+1, false); 
   queue< int > Q;
   Q.push(i);
   c[i] = true;
   while( !Q.empty() && cnt++ <= L){
      int Size = Q.size();
      sum += Size;
      while( Size-- ){
      	 vector< int > &t = v[ Q.front() ];
      	 Q.pop();
      	 for(int j = 0; j < t.size(); j++) if( !c[ t[j] ] ){
      	    c[ t[j] ] = true;
			Q.push( t[j] );
		 }
      }
   }
   cout << sum-1 << endl;
}

int main(){
   cin >> N >> L;
   v.resize( N+1 );
   for(int i = 1; i <= N; i++){
      int n, x;
      scanf("%d", &n);
      while( n-- ){
        scanf("%d", &x);
        v[x].push_back(i);
      }
   }
   cin >> Q;
   while( Q-- ){
      int x;
      scanf("%d", &x);
     
      bfs(x);
   }
   return 0;
}