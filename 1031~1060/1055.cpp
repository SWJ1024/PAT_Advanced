#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

struct node{
   char Name[10];
   int Age, Worth;
   bool operator < (const node &rhs) const {
      if(Worth != rhs.Worth) return Worth > rhs.Worth;
      if(Age != rhs.Age) return Age < rhs.Age;
      return strcmp(Name, rhs.Name) < 0;
   }
};
vector< node > v;

int main(){
   int N, Q;
   cin >> N >> Q;
   v.resize(N);
   for(int i = 0; i < N; i++){
   	  char Name[10];
   	  int Age, Worth;
   	  scanf("%s%d%d", v[i].Name, &v[i].Age, &v[i].Worth);
   }
   sort( v.begin(), v.end() );
   for(int k = 1; k <= Q; k++){
      int n, Amin, Amax, cnt= 0;
      scanf("%d %d %d", &n, &Amin, &Amax);
      printf("Case #%d:\n", k); 
      for(int i = 0; i < N; i++){
	   if( v[i].Age >= Amin && v[i].Age <= Amax ){
	        printf("%s %d %d\n", v[i].Name, v[i].Age, v[i].Worth);
	  	if(++cnt == n) break;
	   }      
      }
      if( !cnt ) printf("None\n");
   }
   return 0;
}
