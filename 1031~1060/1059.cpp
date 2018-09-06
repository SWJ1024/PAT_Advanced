#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL N;
int flag = 1;

bool isprime(LL n){
   if(n == 1) return false;
   for(LL i = 2; i <= sqrt(n)+0.5; i++ ){
      if(n % i == 0) return false;
   }
   return true;
}

void print(LL i, int cnt){
  if(flag) flag = 0;
  else cout << '*';
  cout << i;
  if(cnt != 1) cout << '^' <<cnt;
}

int main(){
   cin >> N;
   cout << N << '=';
   if(N == 1) {
      cout << "1\n";
      return 0;
   }
   for(LL i = 2; N != 1; i++){
      if( N % i == 0 && isprime(i) ){
         int cnt = 0;
         while(N % i == 0){
            N /= i;
            cnt++;
         }
         print(i, cnt);
      }
   }
   return 0;
}