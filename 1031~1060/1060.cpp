#include<bits/stdc++.h>
using namespace std;

int N;
string a, b, s1 = "0.", s2 = "0.";

int p1 = 0,p2 = 0, q1 = 0, q2 = 0;

void f(string &a, string &s1, int &p1, int &q1){
    while( p1 < a.length() && a[p1] != '.') p1++;
    while( q1 < a.length() && ( a[q1] == '0' || a[q1]=='.') ) q1++;
    for(int i = 0,j = q1; i < N; i++){
      if(j >= a.length() ) s1 += '0';
      else if(j == p1) { s1 += a[++j]; j++; }
      else s1 += a[j++];
    }
}

int main(){
   cin >> N >> a >> b;
   f(a, s1, p1, q1);
   f(b, s2, p2, q2);
   if(s1 == s2) cout << "YES " << s1 << "*10^" << ( p1-q1 < 0 ? p1-q1+1 :p1-q1 ) << endl;
   else cout << "NO " << s1 << "*10^" << ( p1-q1 < 0 ? p1-q1+1 : p1-q1 ) << " " << s2 << "*10^" << ( p2-q2 < 0 ? p2-q2+1 : p2-q2) << endl;
   return 0;
}