#include<bits/stdc++.h>
using namespace std;

int main(){
   string a;
   int N;
   cin >> a >> N;
   while( --N ){
      string b;
      int len = a.length();
      for(int i = 0; i < len;){
         int j = i+1;
         while(j < len && a[j] == a[i]) j++;
         b += a[i] + to_string(j-i);
         i = j;
      }
      a = b;
   }
   cout << a;
   return 0;
}