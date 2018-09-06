#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector< int > v;

int main(){
   int N ,S, a;
   cin >> N >> S;
   for(int i = 1; i <= N; i++){
      scanf("%d", &a);
      if( a < S ) v.push_back(a);
   }
   sort(v.begin(), v.end());
   int p = 0, q = v.size()-1;
   while(p < q){
      if(v[p] + v[q] == S){
         cout << v[p] << " " << v[q] <<endl;
         return 0;
      }
      else if(v[p] + v[q] > S) q--;
      else p++;
   }
   cout << "No Solution\n";
   return 0;
}