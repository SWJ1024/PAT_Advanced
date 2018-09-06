#include<bits/stdc++.h>
using namespace std;


int main(){
   string a, b;
   cin >> a >> b;
   int len1 = a.length(), len2 = b.length();
   int m[256], cnt = 0;
   memset(m, 0, sizeof(m));
   for(auto i : a) m[i]++;
   for(auto i : b) {
      if( m[i] ) m[i]--;
      else cnt++;
   }
   if( !cnt ) cout << "Yes " << len1 - len2 << endl;
   else cout << "No " << cnt << endl;
   return 0;
}