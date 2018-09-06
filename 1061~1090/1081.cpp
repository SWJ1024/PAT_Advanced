#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
   return (b == 0) ? a : gcd(b, a%b);
}

int main(){
   int N, a, b, A, B;
   cin >> N;
   for(int i = 0; i < N; i++){
      if(!i ) scanf("%d/%d", &A, &B);
      else {
         scanf("%d/%d", &a, &b);
         A = a*B + b*A;
         B = b*B;
      }
      int K = gcd(A, B);
      A = A / K;
      B = B / K;
   }
   if(A*B < 0){ cout << '-'; A = abs(A); B = abs(B); }
   if(!A)  cout << "0\n";
   else{
      if(A > B)  {
         cout << A/B;
         if( A = A%B ) cout << " ";
      }
      if( A )  cout << A << '/' << B << endl;

   }
   return 0;
}