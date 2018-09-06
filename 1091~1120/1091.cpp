#include<bits/stdc++.h>
using namespace std;

#define _for(i,a,b) for(int i = a; i < b; i++)
bool d[62][1288][130];
const int dx[] = {0,0,1,0,0,-1};
const int dy[] = {0,1,0,0,-1,0};
const int dz[] = {1,0,0,-1,0,0};
int N, M, L, T;
int cnt, ans = 0;

bool inside(int x, int y, int z){
   return (x >= 0 && y >= 0 && z >= 0 && x < L && y < M && z < N);
}

struct node{
   int x, y, z;
};

void bfs(int i, int j, int k){
   queue< node > Q;
   Q.push( {i, j, k} );
   while( !Q.empty() ){
      node temp = Q.front();
	  Q.pop(); 
      for(int t = 0; t < 6; t++){
         int x = temp.x + dx[t], y = temp.y + dy[t], z = temp.z + dz[t];
         if( inside(x, y, z) && d[x][y][z]){
            cnt++;
            d[x][y][z] = false;
            Q.push( {x,y,z} );
         }
      }
  }
}

int main(){
   cin >> M >> N >> L >> T;
   _for(i, 0, L)
      _for(j, 0, M)
         _for(k, 0, N){
            int x;
            scanf("%d", &x);
            if(x) d[i][j][k] = true;
         }
   _for(i, 0, L)
      _for(j, 0, M)
         _for(k, 0, N) if( d[i][j][k] ){
             cnt = 1;
             d[i][j][k] = false;
             bfs(i, j, k);
             if(cnt >= T) ans += cnt;
         }
  cout << ans << endl;
  return 0;
}