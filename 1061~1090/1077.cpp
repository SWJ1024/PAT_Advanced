#include<bits/stdc++.h>
using namespace std;

vector< string >v;
int main(){
   int N;
   string a;
   cin >> N;
   getchar();
   for(int i = 0; i < N; i++){
      getline(cin, a);
      reverse(a.begin(), a.end());
      v.push_back( a );
   }
   int i = 0;
   for(; i < v[0].size(); i++){
      char c = v[0][i];
      bool ok = true;
      for(int j = 1; j < N; j++)
         if( i >= v[j].size() || v[j][i] != c ) ok = false;
      if( !ok ) break;
   }
   if( i )  for(int j = i-1; j >= 0; j--) cout << v[0][j];
   else cout << "nai\n";
   return 0;
}