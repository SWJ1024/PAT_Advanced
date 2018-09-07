#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int N, maxdeep = 0;
vector< int > v, height(MAXN);
int T[MAXN][2];
bool book[MAXN][2];


void build(int i, int id, int x, int deep){
   maxdeep = max( deep, maxdeep );
   height[deep]++;
   if(x <= v[i]){
   	if( !book[i][0] ){
   	   book[i][0] = true;
   	   T[i][0] = id; 
   	}
   	else build( T[i][0], id, x, deep+1);
   }
   else{
        if( !book[i][1] ){
   	   book[i][1] = true;
   	   T[i][1] = id; 
   	}
   	else build( T[i][1], id, x, deep+1);
   }
}


int main(){
   scanf("%d", &N);
   v.resize(N);
   for(int i = 0; i < N; i++){
       scanf("%d", &v[i]);
       if(i) build(0, i, v[i], 0);
   }
   if(N == 1) cout << "1 + 0 = 1\n";
   else printf("%d + %d = %d\n", height[maxdeep], height[maxdeep-1]-height[maxdeep], height[maxdeep-1]);
   return 0;
}
