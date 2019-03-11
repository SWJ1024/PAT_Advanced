#include<bits/stdc++.h>
using namespace std;

bool isprime(string s) {
  int N = stoi(s);
  if (N <= 1) return false;
  int Sqrt = sqrt(N)+0.5;
  for (int i = 2; i <= Sqrt; i++) {
     if (N%i == 0) return false; 
  }
  cout << s << endl;
  return true;
}

int main(){
   int n, m;
   string s;
   cin >> n >> m >> s;
   for (int i = 0; i <= n-m; i++) {
      if (isprime(s.substr(i, m))) return 0; 
   } 
   cout << "404\n";
   return 0;
} 