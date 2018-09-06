#include<bits/stdc++.h>
using namespace std;

string add(string a, string b){
  string sum = "";
  int len = a.length(), c=0, cc=0;
  while(len--){
     cc=c;
     sum=char( ((a[len]+b[len]+cc-'0') > '9') ? (c=1, a[len]+b[len]+cc-'0'-10) : (c=0, a[len]+b[len]+cc-'0')) + sum;
  }
  if(c)  sum = '1'+sum;
  return sum;
}


int main(){
   int T = 10;
   string a, b;
   cin >> a;
   while( T-- ){
   	  b = a;
   	  reverse(b.begin(), b.end());
   	  if(a == b) {
   	  	 cout << a << " is a palindromic number.\n";
   	  	 return 0;
   	  }
   	  cout << a << " + " << b << " = ";
   	  a = add(a, b);
   	  cout << a << endl;
   }
   cout << "Not found in 10 iterations.\n";
   return 0;
}