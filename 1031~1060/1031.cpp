#include<bits/stdc++.h>
using namespace std;

int main(){
   string s;
   cin >> s;
   int len = s.length(), k = (len+2)/3-1, n = len-2*k-2; 
   for(int i = 0; i < k; i++){
      cout << s[i];
      for(int j = 1; j <= n; j++) cout <<" ";
      cout << s[len-1-i]<<endl;
   }
   for(int i = k; i <= len-1-k; i++) cout << s[i];
   return 0;
}