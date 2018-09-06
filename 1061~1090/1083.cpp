#include<bits/stdc++.h>
using namespace std;

struct node{
   char name[15], id[15];
   int point;
   bool operator < (const node &rhs) const{
     return point > rhs.point;
   }
};


int main(){
   int N;
   cin >> N;
   vector< node > v(N);
   for(int i = 0; i < N; i++)   scanf("%s%s%d", v[i].name, v[i].id, &v[i].point);
   sort(v.begin(), v.end() );

   int a, b, ok = 0;
   cin >> a >> b;
   for(auto &i : v){
      if(i.point > b) continue;
      else if(i.point >= a) { printf("%s %s\n", i.name, i.id); ok = 1; }
      else break;
   }
   if( !ok ) cout << "NONE\n";
   return 0;
}