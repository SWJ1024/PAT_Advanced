#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000+10;
const char *Course = "ACME";
int N, M, k;
struct node{
  int id;
  int grade[4], rank[4];
  int bestrank;
  char course;
}stu[maxn];

map<int, string> IDcache;

bool cmp(node a, node b){
   return a.grade[k] > b.grade[k];
}

int main(){
   cin >> N >> M;
   for(int i = 0; i < N; i++){
      scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
      stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
      stu[i].bestrank = maxn;
   }

   for(k = 0; k < 4; k++){
      sort(stu, stu+N, cmp);
      for(int i = 0; i < N; i++){
         if(!i) stu[0].rank[k] = 1;
         else{
            if(stu[i].grade[k] == stu[i-1].grade[k]) stu[i].rank[k] = stu[i-1].rank[k];
            else stu[i].rank[k] = i+1;
         }
         if(stu[i].bestrank > stu[i].rank[k]){
             stu[i].bestrank = stu[i].rank[k];
             stu[i].course = Course[k];
         }
      }
   }

   for(int i = 0; i < N; i++)  IDcache[stu[i].id] = (to_string(stu[i].bestrank) + ' ' + stu[i].course);

   int id;
   for(int i = 0; i < M; i++){
      cin >> id;
      if(!IDcache.count(id) ) cout<<"N/A\n";
      else cout<<IDcache[id]<<endl;
   }
   return 0;
}