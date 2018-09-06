#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int N, head;
struct node{
   int pos, value, next;
   bool operator < (const node & rhs){
      return value < rhs.value;
   }
}Lnode[MAXN];

int main(){
   cin >> N >> head;
   node temp;
   for(int i = 0; i < N; i++){
      scanf("%d%d%d", &temp.pos, &temp.value, &temp.next);
      Lnode[temp.pos] =  temp;
   }
   vector< node > v;
   while(head != -1){
      v.push_back( Lnode[head] );
      head = Lnode[head].next;
   }
   sort(v.begin(), v.end());
   int Size = v.size();
   if( !Size ) {printf("0 -1\n"); return 0;}
   printf("%d %05d\n", Size, v[0].pos);
   for(int i = 0; i < Size; i++){
      if(i != Size-1) printf("%05d %d %05d\n", v[i].pos, v[i].value, v[i+1].pos);
      else printf("%05d %d -1\n", v[i].pos, v[i].value);

   }
   return 0;
}
