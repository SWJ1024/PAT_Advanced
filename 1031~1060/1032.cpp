#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int Next[maxn];

int main(){
   int p, q, n, a, b;
   char c;
   cin >> p >>q >> n;
   while(n--){
      scanf("%d %c %d",&a, &c, &b);
      Next[a] = b;
   }
   unordered_set< int >Set;
   while(p != -1){
     Set.insert(p);
     p = Next[p];
   }
   while(q != -1){
     if( Set.count(q) ) break;
     q = Next[q];
   }
   if(q == -1) cout<<-1<<endl;
   else printf("%05d",q);
   return 0;
}
