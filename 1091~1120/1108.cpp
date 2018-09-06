#include<bits/stdc++.h>
using namespace std;

int main(){
   int N, cnt = 0;
   double sum = 0.0;
   cin >> N;
   while( N-- ){
      string s;
      cin >> s;
      int flag = 1, ok = 1;
      for(int i = 0; i < s.length() && ok; i++){
         if( !isdigit(s[i]) && s[i] != '.' && s[i] != '-' )  ok = 0;
         if( flag && s[i] == '.')  {
            flag = 0;
            if( s.length() - i > 3)  ok = 0;
         }
         else if( !flag && s[i] == '.') ok = 0;
      }
      if( ok && fabs( stof(s) ) <= 1000 ) {sum += stof(s); cnt++; }
      else printf("ERROR: %s is not a legal number\n", s.c_str() );
   }
   if( !cnt ) printf("The average of 0 numbers is Undefined\n");
   else printf("The average of %d number%sis %.2f\n", cnt, (cnt == 1 ? " " : "s "), sum/cnt);
   return 0;
}