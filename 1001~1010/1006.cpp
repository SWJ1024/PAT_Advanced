#include<bits/stdc++.h>
using namespace std;

string first, last;
int firsttime, lasttime;

int main(){
   int N;
   scanf("%d",&N);
   getchar();
   for(int i = 0; i < N; i++){
      string name;
      int h1, m1, s1, h2, m2, s2, t1, t2;
      cin>>name;
      scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
      t1 = h1*3600 + m1*60 + s1;   t2 = h2*3600 + m2*60 + s2;
      if(!i || t1 < firsttime){ firsttime = t1; first = name;}
      if(!i || t2 > lasttime) { lasttime = t2; last = name;}
   }
   cout<<first<<" "<<last<<endl;
   return 0;
}