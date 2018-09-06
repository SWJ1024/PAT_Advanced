#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+10;
int N, K, n = 0, t;
char name1[4], name2[4];
int fa[MAXN], Time[MAXN];
map<int, int> IDCache;
map<int, int> NameCache;

int find( int x ){
	return x == fa[x] ? x : ( fa[x] = find ( fa[x] ) );
}

int getid( char *a ){
   int k = (a[0]-'A')*26*26 + (a[1]-'A')*26 + a[2]-'A';
   if( IDCache.find(k) == IDCache.end() ){
   	  IDCache[k] = n;
   	  NameCache[n++] = k;
   }
   return IDCache[k];
}

void Union(int x, int y, int t){
	Time[x] += t;    Time[y] += t;
	fa[ find(x) ] = find(y);
}

struct node{
	int Sum, Name, p, MAX;
	bool operator < (const node &rhs) const{
	   return Name < rhs.Name;
	}
};

vector< node > Ans;

void print(){
   sort(Ans.begin(), Ans.end());
   cout << Ans.size() << endl;
   for(int i = 0; i < Ans.size(); i++){
      int name = Ans[i].Name;
   	  printf("%c%c%c %d\n", name/26/26+'A', (name/26)%26+'A', name%26+'A', Ans[i].p );
   }
}

int main(){
   for(int i = 0; i < MAXN; i++) fa[i] = i;
   cin >> N >> K;
   while( N-- ){
      scanf("%s%s%d", name1, name2, &t);
   	  Union( getid( name1 ), getid( name2 ), t );
   }
   map< int, node > Mymap;	
   for(int y = 0; y < n; y++){
   	  int x = find(y);
	    Mymap[x].Sum += Time[y];
	    Mymap[x].p++;
	    if( Mymap[x].MAX < Time[y] ){
	        Mymap[x].Name = NameCache[y];
	        Mymap[x].MAX = Time[y];
	    }
   }
   
   for(map<int, node > :: iterator it = Mymap.begin(); it != Mymap.end(); it++)
      if( it->second.Sum > 2*K && it->second.p > 2)
   	     Ans.push_back( it->second );
   print();
   return 0;
} 