#include<bits/stdc++.h>
using namespace std;


int main(){
   int c;
   string a, b;
   cin >> c;
   do{
      a = to_string(c);
      while(a.length() < 4) a += '0';
      sort( a.begin(), a.end() );
      b = a;
      reverse( b.begin(), b.end() );
      c = stoi(b) - stoi(a);
      printf("%04d - %04d = %04d\n", stoi(b), stoi(a), c);
   }while( c != 0 && c != 6174);
   return 0;
}