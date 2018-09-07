#include<bits/stdc++.h>
using namespace std;

int M, N, x;

typedef struct node{
   int v;
   struct node *L, *R;
} *Tree;

Tree build(Tree T, int x){
   if(T == NULL){
      T = new struct node();
      T->L = T->R = NULL;
      T->v = x;
   }
   else if( abs(T->v) > abs(x) ) T->L = build(T->L, x);
   else  T->R = build(T->R, x);
   return T;
}

int CNT;

bool Check( Tree T, int flag, int cnt){	
   if( T == NULL ){
       if( CNT == -1 ) CNT = cnt;
       if( cnt != CNT ) return false;
       else return true;
   }
   cnt += ( T->v > 0 ? 1 : 0 );
   if( flag )
      return Check(T->L, T->v>0?1:0, cnt ) && Check(T->R, T->v>0?1:0, cnt );
   else{
      if( T->v < 0) return false;;
      return Check(T->L, 1, cnt) && Check(T->R, 1, cnt);
   }
}

int main(){
   cin >> M;
   while( M-- ){
      cin >> N;
      Tree T = NULL;
      for(int i = 0; i < N; i++){
          scanf("%d", &x);
          T = build(T, x);
      }
      CNT = -1;
      if( T->v > 0 && Check(T, 1, 0) ) cout << "Yes\n";
      else cout << "No\n";
   }
   return 0;
}
