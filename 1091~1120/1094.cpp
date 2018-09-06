#include<bits/stdc++.h>
using namespace std;


int N, M;
vector< vector< int > > v;
queue< int > q;


int main(){
   cin >> N >> M;
   v.resize( N+1 );
   while( M-- ){
      int ID, K, x;
      cin >> ID >> K;
      while( K-- ){
         scanf("%d", &x);
         v[ID].push_back(x);
      }
   }
   q.push(1);
   int deep = 1, maxsize = 1, generation = 1;
   while( !q.empty() ){
     int Size = q.size();
     if(maxsize < Size){
        maxsize = Size;
        generation = deep;
     }

     while( Size-- ){
        vector <int> &t = v[ q.front() ];
        q.pop();
        for(auto i : t) q.push( i );
     }
     deep++;
   }

   cout << maxsize << " " << generation << endl;
   return 0;
}