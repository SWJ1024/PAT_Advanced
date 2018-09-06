#include<bits/stdc++.h>
using namespace std;

int N, sum = 0, a;
vector< int > v[2];

int main(){
  for(int i = 0; i < 2; i++){
     cin >> N;
     while(N--){
       scanf("%d", &a);
       v[i].push_back(a);
     }
     sort(v[i].begin(), v[i].end());
  }
  int p = v[0].size(), q = v[1].size();
  for(int i = 0; i < p && i < q; i++){
     if(v[0][i] < 0 && v[1][i] < 0) sum += v[0][i]*v[1][i];
     else break;
  }
  for(int i = p-1, j = q-1; i >= 0 && j >= 0; i--, j--){
     if(v[0][i] > 0 && v[1][j] > 0) sum += v[0][i]*v[1][j];
     else break;
  }
  cout << sum << endl;
}