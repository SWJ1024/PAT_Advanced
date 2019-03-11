#include<bits/stdc++.h>
using namespace std;

bool Big = true, Small = true;
void dfs(int i, int N, vector<int> &v, vector<int> &path) {
    path.push_back(v[i]);
    if (2*i > N) {
       int sz = path.size();
       for (int i = 0; i < sz; i++) {
          printf("%d%c", path[i], (i == sz-1 ? '\n' : ' '));
       }
    }
    if (2*i+1 <= N) {
       if(v[2*i+1] > v[i]) Big = false;
       else Small = false;
       dfs(2*i+1, N, v, path);
    }
    if (2*i <= N)  {
       if(v[2*i] > v[i]) Big = false;
       else Small = false;
       dfs(2*i, N, v, path);
   }
   path.pop_back();
}


int main() {
   int N;
   cin >> N;
   vector<int> v(N+1);
   for (int i = 1; i <= N; i++) scanf("%d", &v[i]);
   vector<int> path;
   dfs(1, N, v, path);
   if (Big) cout << "Max Heap\n";
   else if(Small) cout << "Min Heap\n";
   else cout << "Not Heap\n";
}
