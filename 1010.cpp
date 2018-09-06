#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
   string a, b;
   int tag, radix;
   ll sum = 0, MinRadix = 2, MaxRadix, ans;
   cin>>a>>b>>tag>>radix;
   if(tag == 2) swap(a,b);
   for(int i = 0; i < a.length(); i++)  sum = sum*radix+( isdigit(a[i]) ? (a[i]-'0'):(a[i]-'a'+10) );
   for(int i = b.length()-1; i >= 0; i--)
      MinRadix = max(MinRadix, (ll)( isdigit(b[i]) ? (b[i]-'0'+1):(b[i]-'a'+11) )  );
   MaxRadix = sum+1; ans = sum+2;
   while(MinRadix <= MaxRadix){
      ll k = (MinRadix + MaxRadix)/2, Sum = 0;
      for(int i = 0; i < b.length(); i++){
         Sum = Sum*k+( isdigit(b[i] ) ? (b[i]-'0'):(b[i]-'a'+10) );
         if(Sum > sum || Sum < 0) break;
      }
      if(Sum == sum) { ans = min(k, ans); MaxRadix = k-1; }
      else if(Sum > sum || Sum < 0) MaxRadix = k-1;
      else MinRadix = k+1;
   }
   if(ans == sum+2) cout<<"Impossible\n";
   else cout<<ans<<endl;
   return 0;
}