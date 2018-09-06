#include<bits/stdc++.h>
using namespace std;

const char *t[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
   string s;
   int sum = 0;
   cin>>s;
   for(auto it:s) sum += (it - '0');
   if( !sum ) cout<<t[0]<<endl;
   else{
      string Sum = to_string(sum);
      for(int i = 0; i < Sum.length(); i++){
         if(i) cout<<" ";
         cout<<t[ Sum[i]-'0' ];
      }
   }
   return 0;
}