#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e8;
int N, M, x;
int a[MAXN];

int main(){
   cin >> N >> M;
   N *= M;
   M = N/2;
   while(N--){
      scanf("%d", &x);
      if(++a[x] > M){
         cout << x <<endl;
         break;
      }
   }
   return 0;
}