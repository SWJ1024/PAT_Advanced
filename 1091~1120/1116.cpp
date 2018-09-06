#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

bool isprime( int n ){
   if( n == 1) return false;
   for(int i = 2; i <= sqrt(n)+0.5; i++)
      if( n % i == 0) return true;
   return false;
}

int a[MAXN];

int main(){
   int N, K;
   cin >> N;
   for(int i = 1; i <= N; i++){
      int x;
      scanf("%d", &x);
      a[x] = (i != 1 ? i : -1);
   }
   cin >> K;
   set < int > checked;
   while( K-- ){
      int x;
      scanf("%d", &x);
      if( !a[x] ) printf("%04d: Are you kidding?\n", x);
      else if( checked.count(x) ) printf("%04d: Checked\n", x);
      else{
          if( a[x] == -1) printf("%04d: Mystery Award\n", x);
          else if( !isprime( a[x] ) ) printf("%04d: Minion\n", x);
          else printf("%04d: Chocolate\n", x);
          checked.insert(x);
      }
   }
   return 0;
}