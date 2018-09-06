#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int N, K, S;
vector< vector<int> >v;
vector< int > ans, w;

bool cmp(int lhs, int rhs){
   return w[lhs] > w[rhs];
}

void print(){
    for(int i = 0; i < (int)ans.size(); i++)
        printf("%d%c", ans[i], (i == (int)ans.size()-1) ? '\n': ' ');
}

void dfs(int i, int sum){
   int Size = v[i].size();
   if( !Size ){
      if(sum == S) print();
      return;
   }
   for(auto j : v[i]){
      ans.push_back( w[j] );
      dfs(j, sum + w[j]);
      ans.pop_back();
   }
}

int main(){
   cin >> N >> K >> S;
   v.resize(N);
   w.resize(N);
   for(int i = 0; i < N; i++) scanf("%d", &w[i]);
   while(K--){
      int id, M, x;
      cin >> id >> M;
      while(M--){
         scanf("%d", &x);
         v[id].push_back(x);
      }
      sort(v[id].begin(), v[id].end(), cmp);
   }
   ans.push_back( w[0] );
   dfs(0, w[0]);
   return 0;
}