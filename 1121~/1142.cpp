#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200+10;
int N, M, Q;
int n, x;
bool visit[MAXN];
bool d[MAXN][MAXN];


bool check( vector< int > &v ){
	for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++) if( !d[v[i]][v[j]] )
        	return false;   
  return true;
}

bool check2( vector< int > &v, int i ){
   for(int j = 0; j < v.size(); j++)
      if( !d[ v[j] ][ i ] )
         return false;
   return true;	
}

int main(){
   cin >> N >> M;
   for(int i = 0; i < M; i++){
      int a, b;
      scanf("%d%d", &a, &b);
      d[a][b] = d[b][a] = true;
   }
   cin >> Q;
   while(Q--){
   	  bool ok = false;
      vector< int > v;
      set< int > Myset;
      cin >> n;
      for(int i = 0; i < n; i++){
		     scanf("%d", &x);
		     v.push_back(x);
		     Myset.insert(x);
      }
      if( !check( v ) ) cout << "Not a Clique\n";
	    else{
	      for(int i = 1; i <= N; i++) if( !Myset.count(i) ){
	      	  if( check2( v, i ) ) {
	      	  	 ok = true;
	      	  	 break;
	      	  }
	      }
	      if(!ok) cout << "Yes\n";
        else cout << "Not Maximal\n";
      }
   }
   return 0;
}