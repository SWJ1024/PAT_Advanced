#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000000;
int N, b, i = 0;
int s[maxn];

int main(){
   cin >> N >> b;
   if(!N)  cout<<"Yes\n0";
   else {
      while(N > 0){
         s[i++] = N % b;
         N /= b;
      }
      bool flag = true;
      for(int j = 0; j < i/2; j++){
         if(s[j] != s[i-j-1]){
            flag = false;
            break;
         }
      }
      if(flag) cout<<"Yes\n";
      else cout<<"No\n";
      for(int j = i-1; j >= 0; j--){
         cout<<s[j];
         if(j) cout<<" ";
      }
   }
   return 0;
}