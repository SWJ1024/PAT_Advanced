#include<bits/stdc++.h>
using namespace std;

vector< int >inorder, preorder, postorder;

void getpostorder(int inl, int inr, int pre){
   if( inl > inr ) return;
   int i = inl;
   while( inorder[i] != preorder[pre] ) i++;
   getpostorder( inl, i-1, pre+1);
   getpostorder( i+1, inr, pre+1+i-inl);
   postorder.push_back( inorder[i] );
}

int main(){
   int N;
   stack< int > S;
   cin >> N;
   for(int i = 0; i < 2*N; i++){
      string op;
      cin >> op;
      if(op[1] == 'u'){
         int x;
         cin >> x;
         S.push(x);
         preorder.push_back(x);
      }
      else{
         inorder.push_back( S.top() );
         S.pop();
      }
   }

   getpostorder( 0, N-1, 0);

   for(int i = 0; i < N; i++){
     if( i ) putchar(' ');
     cout << postorder[i];
   }
   return 0;
}