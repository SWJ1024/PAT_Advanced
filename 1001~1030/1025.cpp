#include<bits/stdc++.h>
using namespace std;

const int maxn = 105*305;
int N, K, i = 0, start;
struct node{
   char id[20];
   int  point, final_rank, location_number, local_rank;
   bool operator < (const node &rhs ) const {
     return (point == rhs.point)? (strcmp(id, rhs.id) < 0) : (point > rhs.point);
   }
}stu[maxn];

int main(){
   cin >> N;
   for(int t = 1; t <= N; t++){
      cin >> K;
      start = i;
      while(K--){
         scanf("%s%d",stu[i].id, &stu[i].point);
         stu[i++].location_number = t;
      }
      sort(stu+start, stu+i);
      stu[start].local_rank = 1;
      for(int j = start+1, k = 2; j < i; j++, k++){
         if(stu[j].point == stu[j-1].point) stu[j].local_rank = stu[j-1].local_rank;
         else stu[j].local_rank = k;
      }
   }
   sort(stu, stu+i);
   stu[0].final_rank = 1;
   for(int j = 1; j < i; j++){
       if(stu[j].point == stu[j-1].point) stu[j].final_rank = stu[j-1].final_rank;
       else stu[j].final_rank = j+1;
   }
   cout<<i<<endl;
   for(int j = 0; j < i; j++)
      printf("%s %d %d %d\n",stu[j].id, stu[j].final_rank, stu[j].location_number, stu[j].local_rank);
   return 0;
}