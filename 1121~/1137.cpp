#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int M, N, P;
map<string, int > IDcache;

struct node{
	string Name;
	int point, mid, final, G;
	bool operator < (const node &rhs) const{
	   if(G != rhs.G) return G > rhs.G;
	   else return Name < rhs.Name;
	}
}stu[MAXN];

int main(){
   cin >> M >> N >> P;
   string Name;
   int Point, cnt = 0;
   while( M-- ){
   	  cin >> Name >> Point;
      if( Point < 200) continue;
      IDcache[Name] = cnt;
	    stu[cnt++] = {Name, Point, -1, -1, -1};
   }
   while( N-- ){
   	  cin >> Name >> Point;
   	  if( IDcache.find(Name) == IDcache.end() ) continue;
   	  stu[IDcache[Name]  ].mid = Point;
   }   
   
   vector< node > Ans;
   while( P-- ){
   	  cin >> Name >> Point;
   	  if( IDcache.find(Name) == IDcache.end() ) continue;
   	  node &t = stu[ IDcache[Name] ];
   	  t.final = Point;
   	  if(t.final > t.mid) t.G = t.final;
   	  else t.G = t.mid*0.4 + t.final*0.6 + 0.5;
   	  if(t.G >= 60) Ans.push_back(t);
   }
   sort(Ans.begin(), Ans.end());
   
   for(int i = 0; i < Ans.size(); i++)
   	  cout << Ans[i].Name << " " << Ans[i].point << " " << Ans[i].mid << " " << Ans[i].final << " " << Ans[i].G << endl;
   
   return 0;
}