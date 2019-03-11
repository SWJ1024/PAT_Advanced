#include<bits/stdc++.h>
using namespace std;

bool isprime(int n) {
   if (n <= 1) return false;
   int Sqrt = sqrt(n)+0.5;
   for (int i = 2; i <= Sqrt; i++) {
        if (n % i == 0) return false;
   }	
   return true;
}

int main() {
       int n;
       cin >> n;
       bool ok = true;
       while (1) {
             while (!isprime(n)) {
	   ok = false;
	   n++;
             }
             if (isprime(n-6)) {
      	  if (ok) cout << "Yes\n" << n-6 << endl;
                  else cout << "No\n" << n << endl;
                  break;
             }
             else if (isprime(n+6)) {
	  if (ok) cout << "Yes\n" << n+6 << endl;
                  else cout << "No\n" << n << endl;
       	  break;
             }
             else n++;
        } 
        return 0;
}