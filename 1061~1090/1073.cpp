#include<bits/stdc++.h>
using namespace std;

int main(){
   string s, a, b;
   int B;
   cin >> s;
   if( s[0] == '-' )cout << '-';
   for(int i = 0;; i++) if( s[i] == 'E' ){
      a = s.substr(1, i-1) ;
      B = stoi( b = s.substr(i+1) );
      break;
   }
   int len = a.length();
   if(B < 0){
      B = -B;
      cout << "0.";
      for(int i = 1; i <= B-1; i++) cout << '0';
      for(auto i : a) if(i != '.') cout << i;
   }
   else{
      if( len-2 > B){
         B += 2;
         for(int i = 0; i < len; i++) {
             if( a[i] != '.') cout << a[i];
             if(--B == 0) cout << '.';
         }
      }
      else{
         for(int i = 0; i < len; i++) if( a[i] != '.') cout << a[i];
         for(int i = 0; i < (B-len+2); i++) cout << '0';
      }
   }
   return 0;
}