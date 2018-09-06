#include <bits/stdc++.h>
using namespace std;

int C, D, P, N;
vector< pair<int, double> >v;

void init(){
   cin >> C >> D >> P >> N;
   v.push_back( make_pair(D,0.0) );
   for(int i = 0; i < N; i++){
      double p;  int dist;
      scanf("%lf%d", &p, &dist);
      v.push_back( make_pair(dist,p) );
   }
   sort(v.begin(), v.end());
}

void simulation(){
   int p = 0, i = 0;
   double left = 0.0, sum = 0.0, farest;
   if(v[0].first){ printf("The maximum travel distance = 0.00\n"); return;}
   while(p != D){
       farest = p + C*P;
       int j = i+1, cnt = 0;
       while(v[j].first <= farest){
           cnt++;
           if(v[j].second <= v[i].second) break;
           j++;
       }
       if( !cnt ) { printf("The maximum travel distance = %.2f\n", farest); return;}
       else if( v[j].first > farest ){
          sum += (C-left)*v[i].second;
          left = C - ( v[ j = i+1 ].first - v[i].first )*1.0/P;
       }
       else {
          double need = (v[j].first - v[i].first)*1.0/P;
          if(need > left){
             sum += (need-left)*v[i].second;
             left = 0;
          }
          else left = left - need;
       }
       p = v[ i = j].first;
   }
   printf("%.2f\n", sum);
}

int main(){
   init();
   simulation();
   return 0;
}