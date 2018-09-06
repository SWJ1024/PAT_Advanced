#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000+5;
int N, maxdeep = -1, cnt = 0;
bool c[maxn];
vector<vector<int> >v;
set <int> Set;
vector<int>temp;

void dfs(int i, int deep){
   c[i] = true;
   for(int j = 0; j < v[i].size(); j++) if( !c[ v[i][j] ]  ){
      if(deep > maxdeep) {
        temp.clear();
        temp.push_back(v[i][j]);
        maxdeep = deep;
      }
      else if(deep == maxdeep) temp.push_back(v[i][j]);
      dfs(v[i][j], deep+1);
   }
   return;
}

int main(){
   cin >> N;
   v.reserve(N+1);
   for(int i = 0; i < N-1; i++){
      int a, b;
      scanf("%d%d",&a, &b);
      v[b].push_back(a); v[a].push_back(b);
   }
   for(int i = 1; i <= N; i++) if( !c[i] ) {
      cnt++;
      dfs(i, 0);
   }
   if(cnt > 1) cout<<"Error: "<<cnt<<" components\n";
   else if(N == 1) cout<<"1\n";
   else {
      maxdeep = -1;
      fill(c, c+maxn, false);
      for(auto i: temp) Set.insert(i);
      if(!temp.empty()) dfs(temp[0], 0);
      for(auto i: temp) Set.insert(i);
      for(auto &i : Set) cout<<i<<endl;
   }
   return 0;
}