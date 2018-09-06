#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000+5;
int N, K, i = 0;
double wait = 0.0;
priority_queue<int, vector<int>, greater<int> >q;
struct node{
   int t[3], Time, P;
   bool operator < (const node &rhs) const {
      return Time < rhs.Time;
   }
}v[maxn];

int main(){
   cin >> N >> K;
   while(K--){ q.push(8*60*60); }
   while(N--){
      scanf("%d:%d:%d %d", &v[i].t[0], &v[i].t[1], &v[i].t[2], &v[i].P);
      v[i].Time = v[i].t[0]*60*60 + v[i].t[1]*60 + v[i].t[2];
      if(v[i].Time < 17*60*60+1) i++;
   }
   if(!i) {cout<<"0.0\n"; return 0;}
   sort(v, v+i);
   for(int j = 0; j < i; j++){
      int t = q.top(); q.pop();
      if(t > v[j].Time){
         wait += t-v[j].Time;
      }
      q.push( max(v[j].Time, t)+v[j].P*60 );
   }
   printf("%0.1f\n",wait/60.0/i );
   return 0;
}