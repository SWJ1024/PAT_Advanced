#include<bits/stdc++.h>
using namespace std;

int N;
vector< int > pre, in, post, post0;


bool postorder(int inl, int inr, int prel, int flag){
   if(inr < inl) return true;
   int i = inl;
   while( i <= inr && in[i] != pre[prel]) i++;
   if( i > inr ) return false;
   if( flag ){
      if( postorder(i+1, inr, prel+1, 1) && postorder(inl, i-1, inr-i+prel+1, 1) )   post0.push_back( in[i] );
      else return false;
   }
   else{
      if( postorder(inl, i-1, prel+1, 0) && postorder(i+1, inr, i-inl+1+prel, 0) )   post.push_back( in[i] );
      else return false;  
   }
   return true;
}

void print( vector<int> &ans ){
   printf("YES\n");
   for(int i = 0; i < N; i++)
      printf("%d%c", ans[i], (i == N-1) ? '\n' : ' ');
}

int main(){
   cin >> N;
   pre.resize(N);
   in.resize(N);
   for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
   in = pre;
   sort( in.begin(), in.end() );
   if( postorder(0, N-1, 0, 0) ) print( post );
   else if( postorder(0, N-1, 0, 1) ) print( post0 );
   else printf("NO\n");
   return 0;
}