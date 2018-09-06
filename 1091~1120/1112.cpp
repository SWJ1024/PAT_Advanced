#include<bits/stdc++.h>
using namespace std;

unordered_set< char > Wrong, Right, Printed;

int main(){
   string s;
   int K, len;
   cin >> K >> s;
   len = s.length();
   for(int i = 0; i < len; i++){
      int j =  i, ok = 1;
      for(; j < len && j < i+K; j++)
          if( s[j] != s[i] ) ok = 0;
      if( ok && j == i+K && !Right.count(s[i]) ){
         Wrong.insert( s[i] );
         i = j-1;
      }
      else{
         if( Wrong.count(s[i]) )Wrong.erase( s[i] );
         Right.insert( s[i] );
      }
   }
   for(auto &i : s) if( Wrong.count(i) && !Printed.count(i)) {
       cout << i;
       Printed.insert(i);
   }
   putchar('\n');
   for(int i = 0; i < len; i++){
      cout << s[i];
      if( Wrong.count( s[i] ) ) i = i+K-1;
   }
   return 0;
}
