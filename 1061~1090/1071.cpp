#include<bits/stdc++.h>
using namespace std;

string s, ans;
map <string, int> Mymap;
int main(){
   getline(cin ,s);
   for(auto &i: s){
      if( isupper(i) ) i = tolower(i);
      else if( !islower(i) && !isdigit(i) ) i = ' ';
   }
   stringstream ss(s);
   while(ss >> s)   Mymap[s]++;
   int maxn = -1;
   for(auto it : Mymap) if(it.second > maxn ){
      ans = it.first;
      maxn = it.second;
   }
   cout << ans << " " << maxn << endl;
   return 0;
}