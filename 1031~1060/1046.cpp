#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int a[maxn], N;

int main(){
   cin >> N;
   for(int i = 1; i <= N; i++){
      scanf("%d", &a[i]);
      a[i] += a[i-1];
   }
   int A, B, sum = a[N];
   cin >> N;
   while(N--){
      scanf("%d%d", &A, &B);
      if(A > B) swap(A, B);
      cout << min( a[B-1]-a[A-1], sum - (a[B-1]-a[A-1]) ) << endl;
   }
   return 0;
}