#include<bits/stdc++.h>
using namespace std;

const char *Data[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(){
   int flag = 1;
   string a, b;
   cin >> a >> b;
   for(int i = 0;; i++){
      if( flag && isupper(a[i]) && a[i] == b[i] && a[i] <= 'G' ) {
         cout << Data[ (int)(a[i]-'A') ] << " ";
         flag = 0;
      }
      else if( !flag && a[i] == b[i] && ( isdigit( a[i] ) || (a[i] >= 'A' && a[i] <= 'N') ) ){
         printf("%02d:", ( isupper(a[i]) ? (a[i]-'A'+10) : (a[i]-'0') ) );
         break;
      }
   }
   cin >> a >> b;
   for(int i = 0;; i++) if( isalpha(a[i]) && a[i] == b[i] ){
      printf("%02d\n", i);
      break;
   }
   return 0;
}