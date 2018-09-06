#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int a[maxn], b[maxn];

int main(){
   int n, x;
   cin >> n;
   for(int i = 0; i < n; i++){
      scanf("%d", &x);
      a[ b[i] = x ]++;
   }
   for(int i = 0;i < n; i++){
      if(a[ b[i] ] == 1){
         cout << b[i] << endl;
         return 0;
      }
   }
   cout << "None" << endl;
   return 0;
}