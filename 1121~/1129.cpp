#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+10;

struct node{
   int id, Time;
   bool operator < (const node &rhs) const {
      return Time == rhs.Time ?  id < rhs.id  : Time > rhs.Time;
   }
};

set< node > Myset;
int book[MAXN];

int main(){
   int N, M, x;
   cin >> N >> M >> x;
   Myset.insert( {x, 1} );
   book[x]++;
   for(int i = 1; i < N; i++){
      scanf("%d", &x);
      printf("%d:", x);
      int j = 0;
      for(auto it = Myset.begin(); j < M && it != Myset.end(); j++, it++)
         printf(" %d", it->id);
      putchar('\n');
      auto it = Myset.find( {x, book[x]} );
      if(it == Myset.end() )  Myset.insert( {x, 1} );
      else {
         Myset.erase(it);
         Myset.insert( {x, book[x]+1} );
      }
      book[x]++;
   }
   return 0;
}