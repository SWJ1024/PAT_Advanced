#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000+5;
int N, C;
struct node{
   int id, point;
   char name[10];
   bool operator < (const node &rhs) const{
      if(C == 1) return id < rhs.id;
      else if(C == 2)   return (strcmp(name, rhs.name) == 0 )? (id < rhs.id): (strcmp(name, rhs.name) < 0);
      else return (point == rhs.point)? (id < rhs.id): (point < rhs.point);
   }
}stu[maxn];


int main(){
   cin >> N >> C;
   for(int i = 0; i < N; i++) scanf("%d%s%d",&stu[i].id, stu[i].name, &stu[i].point);
   sort(stu, stu+N);
   for(int i = 0; i < N; i++)
   printf("%06d %s %d\n",stu[i].id, stu[i].name, stu[i].point);
   return 0;
}
