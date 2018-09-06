#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
   if(n == 1) return false;
   for(int i = 2; i*i <= n; i++){
      if(n % i == 0) return false;
   }
   return true;
}

int f(int N, int D){
   string s;
   int sum = 0;
   while(N > 0){
      s += (N%D+'0');
      N /= D;
   }
   for(auto it : s){
      sum = sum*D + (it-'0');
   }
   return sum;
}

int main(){
   int N, D;
   while( scanf("%d", &N) && N > 0 && scanf("%d", &D) ){
      if(isprime(N) && isprime( f(N,D) ) ) cout<<"Yes\n";
      else cout<<"No\n";
   }
  
   return 0;
}