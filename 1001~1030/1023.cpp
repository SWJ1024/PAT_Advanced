#include<bits/stdc++.h>
using namespace std;

int main(){
   string s, sum, sum0;
   cin >> s;
   reverse(s.begin(), s.end() );
   int len = s.length(), c = 0;
   for(int i = 0; i < len; i++){
   int t = (s[i]-'0')*2 + c;
      sum += (t%10 + '0');
      c = t / 10;
   }
   if(c) sum += '1';
   reverse(sum.begin(), sum.end() );
   sum0 = sum;
   sort(s.begin(), s.end());
   sort(sum.begin(), sum.end());
   if(s == sum) cout<<"Yes\n";
   else cout<<"No\n";
   cout<<sum0<<endl;
   return 0;
} 
