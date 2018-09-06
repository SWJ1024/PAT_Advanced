#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL mul(int len){
   LL res = 1;
   for(int i = 2; i < 2+len; i++) res *= i;
   return res;
}

bool isprime(LL N){
   if(N <= 1) return false;
   for(int i = 2; i <= sqrt(N)+0.5; i++)
      if(N % i == 0) return false;
   return true;
}

int main(){
   LL N;
   int p, q;
   cin >> N;
   if( isprime(N) ) cout << "1\n" << N <<endl;
   else for(int len = 11; len >= 1; len--){
      p = 2, q = 1+len;
      LL sum = mul( len );
      while( sum <= N ){
         if( N % sum == 0 ){
            cout << q+1-p << endl << p;
            while(p < q) cout << '*' << ++p;
            return 0;
         }
         sum = sum / p++ * ++q;
      }
   }
   return 0;
}