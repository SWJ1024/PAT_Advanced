#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int A[MAXN];
int N, P;
long int ans = 1;

int main(){
   cin >> N >> P;
   for(int i = 0; i < N; i++)   scanf("%d", &A[i]);
   sort(A, A+N);
   for(int i = N-1; i >= 0; i--){
      double k = A[i]*1.0 / P;
      ans = max( i - ( lower_bound(A, A+N, k) -A ) + 1, ans);
   }
   cout << ans << endl;
   return 0;
}