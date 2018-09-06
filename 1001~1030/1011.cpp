#include<bits/stdc++.h>

using namespace std;



int main(){

   int T = 3;

   double sum = 1, a, b, c;

   while(T--){

     cin >> a >> b >> c;

     if(a > b){

         if(a > c) {cout << "W "; sum *= a;}

         else      {cout << "L "; sum *= c;}
 
     }

     else{

         if(b > c) {cout << "T "; sum *= b;}

         else      {cout << "L "; sum *= c;}
 
     }

    }

    printf("%.2f\n",(0.65*sum - 1)*2);

    return 0;

}