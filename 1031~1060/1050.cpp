#include<bits/stdc++.h>
using namespace std;

const int MAXN = 256;
int ASCII[MAXN];

int main(){
   string s, s1;
   getline(cin, s);
   getline(cin, s1);
   for(char &i : s1) ASCII[ int(i) ] = 1;
   for(char &i : s) if( !ASCII[ int(i) ] ){
      cout << char(i);
   }
   return 0;
}
