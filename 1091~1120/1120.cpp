#include<bits/stdc++.h>
using namespace std;

int main(){
   int N, cnt = 0;
   set< int > Myset;
   cin >> N;
   while( N-- ){
      string s;
      cin >> s;
      int sum = 0;
      for(auto i : s) sum += int(i -'0');
      Myset.insert( sum );
   }
   cout << Myset.size() << endl;
   for(auto i : Myset){
      if( cnt++ ) putchar(' '); 
      cout << i;
   }
   return 0;
}