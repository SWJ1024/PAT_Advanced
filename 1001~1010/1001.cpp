#include<bits/stdc++.h>
using namespace std;

int main(){
   int a, b, c;
   cin >> a >> b;
   c = a+b;
   if(c < 0) {  putchar('-'); c = -c;}
   string s = to_string(c);
   int len = s.length(), k = len/3, t = len-3*k;
   for(int i = 0; i < len; i++){
      cout << s[i];
      if( i != len-1 && (i-t+1)%3 == 0) cout<<',';
   }
   return 0;
}