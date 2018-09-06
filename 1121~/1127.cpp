#include<bits/stdc++.h>
using namespace std;

int N;
vector< int > in, post;
vector< vector<int> > v;

void zigzagging(int inl, int inr, int postr, int deep){
   if(inl > inr) return;
   int i = inl;
   while( in[i] != post[postr] ) i++;
   v[deep].push_back( in[i] );
   zigzagging(inl, i-1, i+postr-inr-1, deep+1);
   zigzagging(i+1, inr, postr-1, deep+1);
}

int main(){
   cin >> N;
   in.resize(N);
   post.resize(N);
   v.resize(N);
   for(int i = 0; i < N; i++) scanf("%d", &in[i]);
   for(int i = 0; i < N; i++) scanf("%d", &post[i]);
   zigzagging(0, N-1, N-1, 0);
   int k = 0;
   vector< int > ans;
   for(auto &V : v){
      if(k) for(int i = 0; i < (int)V.size(); i++)
         ans.push_back( V[i] );
      else  for(int i = (int)V.size()-1; i >= 0 ; i--)
        ans.push_back( V[i] );
      k ^= 1;
   }
   for(int i = 0; i < (int)ans.size(); i++)
       printf("%d%c", ans[i], (i == (int)ans.size()-1) ? '\n' : ' ' );
   return 0;
}