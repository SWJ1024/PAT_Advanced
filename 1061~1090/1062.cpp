#include<bits/stdc++.h>
using namespace std;

int N, L, H;
struct node{
   int id, V, T, grade;
   bool operator < (const node &rhs) const{
      if(grade != rhs.grade) return grade > rhs.grade;
      else if( V != rhs.V ) return V > rhs.V;
      else return id < rhs.id;
   }
}temp;
vector< node > v[4];

int main(){
   cin >> N >> L >> H;
   for(int i = 0; i < N; i++){
      scanf("%d%d%d", &temp.id, &temp.V, &temp.T);
      temp.grade = temp.V + temp.T;
      if(temp.V >= H && temp.T >= H) v[0].push_back( temp );
      else if(temp.V >= H && temp.T >= L) v[1].push_back( temp );
      else if(temp.V >= L && temp.T >= L && temp.V >= temp.T) v[2].push_back( temp );
      else if(temp.V >= L && temp.T >= L) v[3].push_back( temp );
   }
   for(int i = 0; i < 4; i++) sort( v[i].begin(), v[i].end() );
   printf("%d\n", v[0].size() + v[1].size() + v[2].size() + v[3].size() );
   for(int i = 0; i < 4; i++){
      for(auto &it : v[i])
         printf("%08d %d %d\n", it.id, it.V, it.T);
   }
   return 0;
}