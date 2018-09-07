#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b){
   return (b == 0) ? a : gcd(b, a%b);
}


void form(ll A, ll B){
   ll K = gcd( abs(A), abs(B) );
   A = A / K;
   B = B / K;
   bool ok = false;
   if( (A < 0 && B > 0) || (A > 0 && B < 0) ){ cout << "(-";  ok = true;}A = abs(A); B = abs(B);
   if(A >= B)  {
      cout << A/B;
      if( A = A%B ) cout << " ";
   }
   if( A )  cout << A << '/' << B;
   if( ok ) cout << ")";
}

ll a, b, c, d;

int main(){ 
   scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
   form(a, b); cout << " + "; form(c, d); cout << " = "; form(a*d+b*c, b*d); cout << '\n';
   form(a, b); cout << " - "; form(c, d); cout << " = "; form(a*d-b*c, b*d); cout << '\n';
   form(a, b); cout << " * "; form(c, d); cout << " = "; form(a*c, b*d); cout << '\n';
   form(a, b); cout << " / "; form(c, d); cout << " = ";
   if(c == 0) cout << "Inf\n";
   else { form(a*d, b*c); cout << '\n'; }
   return 0;
}
