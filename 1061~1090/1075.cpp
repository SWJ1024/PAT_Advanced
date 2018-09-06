#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+5, MAXP = 5+2;;
int p[MAXP];

struct node{
   int score[MAXP], mark[MAXP];
   int Rank, id, sum, perfect, flag;
   bool operator < (const node &rhs) const{
      if(flag != rhs.flag) return flag > rhs.flag;
      else if(sum != rhs.sum) return sum > rhs.sum;
      else if(perfect != rhs.perfect) return perfect > rhs.perfect;
      else return id < rhs.id;
   }
}a[MAXN];

int main(){
   int N, K, M;
   cin >> N >> K >> M;
   for(int i = 0; i < K; i++) scanf("%d", &p[i]);
   while( M-- ){
      int id, promble, point;
      scanf("%d%d%d", &id, &promble, &point);
      a[id].id = id; promble--;
      if( a[id].score[promble] < point ){
         a[id].sum = a[id].sum - a[id].score[promble] + point;
         a[id].score[promble] = point;
         if(point == p[promble]) a[id].perfect++;
      }
      a[id].mark[ promble ] = 1;
      if( point >= 0) a[id].flag = 1;
   }
   sort(a+1, a+N+1);
   for(int i = 1; i <= N; i++){
      if( a[i].sum == a[i-1].sum ) a[i].Rank = a[i-1].Rank;
      else a[i].Rank = i;
   }

   for(int i = 1; i <= N; i++){
      if(a[i].flag <= 0) break;
      printf("%d %05d %d", a[i].Rank, a[i].id, a[i].sum);
      for(int k = 0; k < K; k++){
         if( a[i].mark[k] != 0 ) cout << " " << a[i].score[k];
         else cout << " -";
      }
      putchar('\n');
   }
   return 0;
}