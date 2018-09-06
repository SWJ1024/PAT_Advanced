#include<bits/stdc++.h>
using namespace std;

const long int MOD = 1000000007;

int main(){
   string s;
   cin >> s;
   const int N = s.length();
   vector< int > v(N);
   if(s[N-1] == 'T') v[N-1] = 1;
   for(int i = N-2; i > 0; i--)
      v[i] = ( s[i] == 'T') ? ( v[i+1] + 1 ): v[i+1];
   long int sum = 0, ans = 0;

   for(int i = 0; i < N; i++){
      if( s[i] == 'P' ) sum++;
      else if( s[i] == 'A' ) ans = (ans + (sum*v[i]) % MOD ) % MOD;
   }
   cout << ans << endl;
   return 0;
}