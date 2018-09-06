#include<bits/stdc++.h>
using namespace std;

typedef struct node{
   int v;
   struct node *L, *R;
} *Tree;


Tree RR( Tree &T ){
   Tree temp = T->L;
   T->L = temp->R;
   temp->R = T;
   return temp;
}

Tree LL( Tree &T ){
   Tree temp = T->R;
   T->R = temp->L;
   temp->L = T;
   return temp;
}

int GetNum( Tree T ){
   if( T == NULL ) return 0;
   else return 1+max( GetNum(T->L) , GetNum(T->R) ); 
}

void build(Tree &T, int x){
   if( T == NULL ){
   	  T = new struct node();
      T->R = T->L = NULL;
      T->v = x;
   }
   else if( T->v > x ){
      build(T->L, x);
      if( GetNum(T->L)-GetNum(T->R) >= 2 ){
         if( T->L->v < x) T->L = LL(T->L);
         T = RR(T);
      }
   }
   else if( T->v < x ){
      build(T->R, x);
      if( GetNum(T->R)-GetNum(T->L) >= 2 ){
         if( T->R->v > x) T->R = RR(T->R);
         T = LL(T);
      }
   }
}

int main(){
   int N, x;
   cin >> N;
   Tree T = NULL;
   for(int i = 0; i < N; i++){
      cin >> x;
      build(T, x);
   }
   cout << T->v << endl;
   return 0;
}