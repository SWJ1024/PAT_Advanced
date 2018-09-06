#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int a[MAXN], b[MAXN];

int main(){
   int N;
   cin >> N;
   scanf("%d", &a[0]);
   b[0] = -1;
   for(int i = 1; i < N; i++){
      scanf("%d", &a[i]);
      b[i] = max( a[i-1], b[i-1] );
   }

   vector< int > ans;
   int k = 1e9+10;
   for(int i = N-1; i > 0; i--){
      if( a[i] > b[i] && a[i] < k) ans.push_back( a[i] );
      k = min( a[i], k);
   }
   if(a[0] < k) ans.push_back( a[0] );
   sort(ans.begin(), ans.end());
   cout << ans.size() << endl;
   for(int i = 0; i < ans.size(); i++){
      if( i ) putchar(' ');  
      cout << ans[i];
   }
   putchar('\n');
   return 0;
}