#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e4+10, MAXC = 100+10;
int N, M, K;
int quota[MAXC];
vector< int > v[MAXC];

struct node{
   int ID;
   int GE, GI;
   int c[5], choose;
   double average;
   bool operator < (const node &rhs){
      return (average == rhs.average) ? (GE > rhs.GE) : (average > rhs.average);
   }
};

bool judge(node &a, node &b, int school){
   if(a.average > b.average)  return false;
   if(a.GE > b.GE) return false;
   if(a.choose != school ) return false;
   return true;
}

int main(){
   cin >> N >> M >> K;
   vector< node > stu(N);
   for(int i = 0; i < M; i++) scanf("%d", &quota[i]);
   for(int i = 0; i < N; i++){
      scanf("%d%d", &stu[i].GE, &stu[i].GI);
      for(int j = 0; j < K; j++)  scanf("%d", &stu[i].c[j]);
      stu[i].ID = i; stu[i].average = (stu[i].GI+stu[i].GE)/2.0;
   }
   sort(stu.begin(), stu.end() );

   for(int i = 0; i < N; i++){
      node &t = stu[i];
      for(int j = 0; j < K; j++){
         int school = t.c[j];
         if( !i || quota[ school ] > 0 || judge(stu[i-1], stu[i], school) ){
            v[ school ].push_back( t.ID );
            quota[ school ]--;
            t.choose = school;
            break;
         }
      }
   }

   for(int i = 0; i < M; i++){
       sort(v[i].begin(), v[i].end());
       for(int j = 0; j < v[i].size(); j++){
          if( j ) cout << " ";
          cout << v[i][j];
       }
       cout << '\n';
   }
   return 0;
}