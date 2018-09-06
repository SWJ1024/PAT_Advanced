#include<bits/stdc++.h>
using namespace std;

const int maxn = 100+5;
vector< vector<int> >v;
int N, M;

int main(){
   cin>> N >> M;
   v.resize(N+1);
   while(M--){
      int id, k, child;
      cin >> id >> k;
      while(k--){
         cin >> child;
         v[id].push_back(child);
      }
   }
   int k = 1, sum;
   queue<int>q;
   q.push(1);
   while(1){
      sum = 0;
      while(k--){
         int u = q.front();  q.pop();
         if(v[u].empty()) sum++;
         else for(auto it : v[u]) q.push(it);
      }
      cout<<sum;
      if(k = q.size()) cout<<" ";
      else break;
   }
   return 0;
}