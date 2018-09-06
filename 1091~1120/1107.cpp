#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000+5;
int a[MAXN], fa[MAXN];
int N;

int findfa( int x ){
   return  x == fa[x]  ?  x : x = findfa( fa[x] ) ;
}

void Union(int x, int father){
   fa[ findfa(x) ] = father;
}

int main(){
   cin >> N;
   for(int i = 1; i <= N; i++) fa[i] = i;
   for(int i = 1; i <= N; i++){
      int n, x;
      scanf("%d:", &n);
      int father = findfa(i);
      while( n-- ){
        scanf("%d", &x);
        if( !a[x] ) a[x] = i;
        Union(a[x], father);
      }
   }
   map <int, int> Mymap;
   for(int i = 1; i <= N; i++)   Mymap[ findfa(i) ]++;
   vector< int > ans;
   for(auto &i : Mymap) ans.push_back( i.second );
   sort(ans.begin(), ans.end() );
   cout << ans.size() << endl;

   for(int i = ans.size()-1; i >= 0; i--){
      printf("%d%c", ans[i], ( i ? ' ': '\n' ) );
   }
   return 0;
}