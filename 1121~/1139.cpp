#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300+5;
int N, M, n = 0;
unordered_map<int, int> IDCache;
unordered_map<int, int> NameCache;
int d[MAXN][MAXN];
char s1[10], s2[10];

int getid( char *s ){
  int x = abs( atoi(s) ), X = x;
  if( s[0] != '-' )  x += 10000;
  if( !IDCache.count( x ) ){
      IDCache[ x ] = n;
      NameCache[ n++ ] = X;
  }
  return IDCache[ x ];
}

int main(){
   cin >> N >> M;
   while( M-- ){
      scanf("%s%s", s1, s2);
      int idx = getid( s1  );
      int idy = getid( s2 );
      d[idx][idy] = d[idy][idx] = strlen(s1) == strlen(s2) ? 1 : -1 ;
   }
   cin >> N;
   while( N-- ){
      scanf("%s%s", s1, s2);
      int idx = getid( s1  );
      int idy = getid( s2 );
      vector< pair<int, int> > v;
      int flag = strlen(s1) == strlen(s2) ? 1 : -1 ;
      for(int i = 0; i < n; i++) if( i != idy && d[idx][i] == 1 )
   	  for(int j = 0; j < n; j++) if(j != idx && d[i][j] == flag && d[j][idy] == 1)
   	  	v.push_back( make_pair( NameCache[i], NameCache[j] ) );
      sort(v.begin(), v.end());
      cout << v.size() << endl;
	 for(int i = 0; i < v.size(); i++)
	     printf("%04d %04d\n", v[i].first, v[i].second);	   
   }
   return 0;
}
