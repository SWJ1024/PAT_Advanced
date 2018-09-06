#include<bits/stdc++.h>
using namespace std;

string Getsum(string s){
   string sum, s0 = s;
   int c = 0, len = s.length();
   reverse(s.begin(), s.end() );
   for(int i = 0; i < len; i++){
      int t = (s[i] + s0[i] - 2 *'0' + c);
      sum += (t%10 + '0');
      c = t / 10;
   }
   if(c) sum += '1';
   reverse(sum.begin(), sum.end() );
   return sum;
}

bool ispalindeomic(string s){
   string s0 = s;
   reverse(s0.begin(), s0.end());
   if(s0 == s) return true;
   else return false;
}

int main(){
   string s;
   int N, T = 0;
   cin >> s >> N;
   if(ispalindeomic(s) ){
      cout<<s<<"\n0\n";
      return 0;
   }
   while(N--){
      T++;
      if( ispalindeomic( s = Getsum(s)  ) ) break;
   }
   cout<<s<<endl<<T<<endl;
   return 0;
}