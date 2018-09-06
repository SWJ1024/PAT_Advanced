#include<bits/stdc++.h>
using namespace std;


set< char > Right, Wrong;

int main(){
   string In, Out;
   cin >> In >> Out;
   for(auto &i : Out){
      if( islower(i) )  i = toupper(i);
      Right.insert(i);
   }

   for(auto &i : In){
      if( islower(i) )  i = toupper(i);
      if( Wrong.count(i) || Right.count(i) ) continue;
      cout << i;
      Wrong.insert(i);
   }
   return 0;
}