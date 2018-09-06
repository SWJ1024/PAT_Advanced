#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
int a[MAXN];

int main(){
   int N;
   cin >> N;
   for(int i = 0; i < N; i++){
      int x;
      scanf("%d", &x);
      a[x]++;
   }
   int cnt = 0;
   for(int i = MAXN-1;; i--){
      if( cnt >= i ){
         cout << i << endl;
         break;
      }
      cnt += a[i];
   }
   return 0;
}