#include<bits/stdc++.h>
using namespace std;

int main(){
   int T;
   cin >> T;
   while( T-- ){
      string s;
      long long a, b, c;
      cin >> s;
      a = stoi(s);
      b = stoi( s.substr(0, s.length()/2 ) );
      c = stoi( s.substr( s.length()/2 ) );
      if( b*c != 0 && a % (b*c) == 0) cout << "Yes\n";
      else cout << "No\n";
   }
   return 0;
}