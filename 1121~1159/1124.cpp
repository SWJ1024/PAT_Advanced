#include<bits/stdc++.h>
using namespace std;

set< string > Myset;

int main(){
   int N, M, P, cnt = 0;
   cin >> N >> M >> P;
   for(int i = 1; i <= N; i++){
       string s;
       cin >> s;
       if( ++cnt >= P && cnt % M == P % M ){
          if( Myset.count(s) )  cnt--;
          else {
            cout << s << endl;
            Myset.insert(s);
          }
       }
   }
   if( Myset.empty() ) cout << "Keep going...\n";
   return 0;
}