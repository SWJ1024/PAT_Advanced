#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;
int dp[MAXN][MAXN], Maxlength = 1;

int main(){
   string s;
   getline(cin, s);
   int n = s.length();
   for(int i = 0; i < n; i++){
   	  dp[i][i] = 1;
	    if(i && s[i-1] == s[i] ) dp[i-1][i] = Maxlength = 2;
   }
   for(int k = 3; k <= n; k++)
   	  for(int j = 0; j+k-1 < n; j++)
   	  	 if( s[j+k-1] == s[j] && dp[j+1][j+k-2] == k-2 ) dp[j][j+k-1] = Maxlength = k;
   cout << Maxlength << endl;
   return 0;
}