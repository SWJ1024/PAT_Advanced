#include<bits/stdc++.h>
using namespace std;

typedef struct node{
   int key;
   struct node *Left, *Right;
} *Tree;

Tree L(Tree T){
    Tree temp = T->Right;
    T->Right = temp->Left;
    temp->Left = T;
    return temp;
}

Tree R(Tree T){
    Tree temp = T->Left;
    T->Left = temp->Right;
    temp->Right = T;
    return temp;
}

int getHeight(Tree T){
   if( T == NULL) return 0;
   else return max( getHeight(T->Left) , getHeight(T->Right) ) + 1;
}

void balance( Tree &T, int x){
   int lheight = getHeight( T->Left ), rheight = getHeight( T->Right);
   if( lheight - rheight >= 2 ){
       if(T->Left->key < x) T->Left = L(T->Left);
       T = R(T);
   }
   else if( rheight - lheight >= 2 ){
       if(T->Right->key > x) T->Right = R(T->Right);
       T = L(T);
   }
}

Tree build(Tree T, int x){
   if( T == NULL ){
      Tree u = (Tree) malloc( sizeof(struct node) );
      u->key = x;
      u->Left = u->Right = NULL;
      return u;
   }
   if( x < T->key )  T->Left = build(T->Left, x);
   else T->Right = build(T->Right, x);
   balance( T, x);
   return T;
}

bool levelorder(Tree T){
   bool ok = true;
   int flag = 0;
   vector< int > v;
   queue< Tree > Q;
   Q.push( T );
   while( !Q.empty() ){
      Tree u = Q.front();
      v.push_back(u->key);
      Q.pop();
      if( u->Left && u ->Right ){
         Q.push(u->Left); Q.push(u->Right);
         if( flag ) ok = false;
      }
      else if( u->Left ) { Q.push(u->Left);  if( flag ) ok = false; flag = 1;}
      else if( u->Right) { Q.push(u->Right); ok = false;}
      else flag = 1;
   }
   for(int i = 0; i < (int)v.size(); i++)
      printf("%d%c", v[i], (i == (int)v.size()-1) ? '\n' : ' ');
   return ok;
}

int main(){
   int N;
   cin >> N;
   Tree T = NULL;
   for(int i = 0; i < N; i++){
     int x;
     scanf("%d", &x);
     T  = build(T, x);
   }
   if( levelorder(T) ) cout << "YES\n";
   else cout << "NO\n";
   return 0;
}