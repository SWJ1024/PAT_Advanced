#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int book[MAXN];

int main(){
   fill(book, book+MAXN, -1);   
   int N, M;
   cin >> N;
   while( N-- ){
      int x, y;
      scanf("%d%d", &x, &y);
      book[x] = y;
      book[y] = x;
   }
   cin >> M;
   set < int > Myset;
   while( M-- ){
      int x;
      scanf("%d", &x);
      if( book[x] != -1 && Myset.find( book[x] ) != Myset.end() ) Myset.erase( book[x] );
      else Myset.insert(x);
   }
   cout << Myset.size() << endl;
   int cnt = 0;
   for(auto i : Myset){
      if( cnt++ ) putchar(' ');
      printf("%05d", i);
   }
   return 0;
}