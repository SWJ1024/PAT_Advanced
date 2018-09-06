#include<bits/stdc++.h>

using namespace std;


int N;

vector<int>post, in;

vector<vector<int> >level;


void levelorder(int postr, int inl, int inr, int h){
   
    if(inl > inr)   return ;
   
    int i = inl;
   
    while(in[i] != post[postr]) i++;

    level[h].push_back( in[i] );

    levelorder(i-inr+postr-1, inl, i-1, h+1);

    levelorder(postr-1, i+1, inr, h+1);

}



void print(){
   
   for(int h = 0;; h++){
      
       for(int i = 0; i < level[h].size(); i++){

         cout<<level[h][i];

         if(--N) cout<<" ";

         else return;

      }

   }

}



int main(){
   
   cin >> N;

   post.resize(N), in.resize(N), level.resize(N);

   for(int i = 0; i < N; i++) cin >> post[i];

   for(int i = 0; i < N; i++) cin >> in[i];

   levelorder(N-1, 0, N-1, 0);

   print();

   return 0;

}