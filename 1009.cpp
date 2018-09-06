#include<bits/stdc++.h>
using namespace std;

map<int, double> Map0, Map1;


int main(){
   int K, N;
   double a;
   cin >> K;
   while(K--){
      cin >> N >> a;
      Map0[N] = a;
   }
   cin >> K;
   while(K--){
      cin >> N >> a;
      for(auto it: Map0)  Map1[ it.first + N ] += (it.second * a);
   }
   int cnt = 0;
   for(auto it : Map1)
     if(it.second != 0.0) cnt++;
   cout << cnt;

   for(auto it = prev(Map1.end());; it--){
     if(it->second != 0.0)  printf(" %d %.1f",it->first,it->second);
     if(it == Map1.begin() ) break;
   }
   return 0;
}