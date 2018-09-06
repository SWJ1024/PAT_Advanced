#include<bits/stdc++.h>
using namespace std;

void MarColor(int n){
   if(n < 10) cout<<n;
   else cout << char(n-10+'A');
   return;
}

int main(){
   int T = 3, n;
   cout << '#';
   while(T--){
      cin >> n;
      MarColor( n/13 );
      MarColor( n%13 );
   }
   return 0;
}
