#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000+10;
int rate[25];
char Status[25];
int N, month;
struct node{
   string name;
   int t[3], Time, status, money;
   bool operator < (const node &rhs) const{
      return ( name == rhs.name )? (Time < rhs.Time): (name < rhs.name) ;
   }
}Record[maxn];


int f(int dd, int hh, int mm){
   int sum = dd*rate[24]*60;
   if(hh)  sum += rate[hh]*60;
   sum += (rate[hh+1]-rate[hh])*mm;
   return sum;
}

int main(){
   for(int i = 1; i <= 24; i++){
      cin >> rate[i];
      rate[i] += rate[i-1];
   }

   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> Record[i].name;
      scanf("%d:%d:%d:%d%s",&month, &Record[i].t[0], &Record[i].t[1], &Record[i].t[2], Status);
      Record[i].status = ( Status[1] == 'n');
      Record[i].Time = Record[i].t[0]*24*60 +Record[i].t[1]*60 + Record[i].t[2];
      Record[i].money = f(Record[i].t[0], Record[i].t[1], Record[i].t[2]);
   }
   sort(Record, Record+N);
   map<string, vector<node> > Map;
   for(int i = 0; i < N-1; i++){
      if(Record[i].name != Record[i+1].name || !Record[i].status || Record[i+1].status ) continue;
      Map[ Record[i].name ].push_back(Record[i]);
      Map[ Record[i].name ].push_back(Record[i+1]);
   }


   for(auto &it: Map){
      vector<node> &v = it.second;
      cout<<v[0].name;
      printf(" %02d\n",month);
      double sum = 0.0;
      for (int i = 0; i < v.size()-1; i += 2) {
         printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",v[i].t[0], v[i].t[1], v[i].t[2], v[i+1].t[0], v[i+1].t[1], v[i+1].t[2], v[i+1].Time-v[i].Time, (v[i+1].money-v[i].money)/100.0);
         sum += (v[i+1].money-v[i].money)/100.0;
      }
      printf("Total amount: $%.2f\n",sum);
   }
   return 0;
}