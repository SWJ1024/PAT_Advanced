#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int sq[MAXN];

int main(){
   int M, N, K;
   cin >> M >> N >> K;
   while(K--){
      stack< int > S;
      for(int i = 1; i <= N; i++) scanf("%d", &sq[i]);
      int i = 1, j = 0;
      bool ok = false;
      while(1){
         if(!S.empty() && S.top() == sq[i]){
            S.pop();
            if(++i > N) {
                ok = true;
                break;
            }
         }
         else{
            S.push(++j);
            if((int)S.size() > M || j > N)  break;
         }
      }
      if(ok) cout << "YES\n";
      else cout << "NO\n";
   }
   return 0;
}