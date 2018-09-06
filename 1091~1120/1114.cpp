#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int N;
int fa[MAXN];
bool book[MAXN];


int find( int x ){
   return (x == fa[x]) ? x : (fa[x] = find( fa[x] ));
}


void Union(int x, int y){
   book[y] = true;
   fa[ find(y) ] = x;
}

struct node{
   int estate, Area;
   int cnt, id;
   bool operator < (const node &rhs ) const {
      if( Area*rhs.cnt != rhs.Area*cnt ) return Area*rhs.cnt > rhs.Area*cnt;
      return id < rhs.id;
   }
}family[MAXN], Ans[MAXN];

int main(){
   for(int i = 0; i <= MAXN; i++) fa[i] = i;
   cin >> N;
   for(int i = 0; i < N; i++){
      int ID, Father, Mother, k, Child, estate, Area;
      scanf("%d%d%d%d", &ID, &Father, &Mother, &k);
      book[ID] = true;
      ID = find(ID);
      if( Father != -1 ) Union(ID, Father);
      if( Mother != -1 ) Union(ID, Mother);
      while( k-- ){
         scanf("%d", &Child);
         Union(ID, Child);
      }
      scanf("%d%d", &estate, &Area);
      family[ID].estate += estate;
      family[ID].Area += Area;
   }
   
   map<int, int> Mymap;
   int cnt = 0;
   for(int i = 0; i < MAXN; i++) if( book[i] ){
      int fa = find(i);
      if( Mymap.find(fa) == Mymap.end() )   Mymap[fa] = cnt++;
      int t = Mymap[fa];
      Ans[t].estate += family[i].estate;
      Ans[t].Area += family[i].Area;
      Ans[t].id = (Ans[t].cnt == 0 ) ? i : min(i, Ans[t].id);
      Ans[t].cnt++;
   }
   
   sort(Ans, Ans+cnt);
   cout << cnt << endl;
   for(int i = 0; i < cnt; i++)
      printf("%04d %d %.3f %.3f\n", Ans[i].id, Ans[i].cnt, Ans[i].estate*1.0/Ans[i].cnt, Ans[i].Area*1.0/Ans[i].cnt);
   return 0;
}