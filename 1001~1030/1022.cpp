#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000+5;
int N, M;
map<string, set<int> > Map[6];

int main(){
  string s;
  cin >> N;
  while(N--){
     int id;
     scanf("%d\n",&id);
     for(int i = 1; i <= 5; i++){
        getline(cin, s);
        if(i != 3 ) Map[i][s].insert(id);
        else {
          stringstream xx(s);
          while(xx >> s) Map[i][s].insert(id);
        }
     }
  }

  cin >> M;
  while(M--){
     int a;
     scanf("%d: ", &a);
     getline(cin, s);
     cout<<a<<": "<<s<<endl;
     set<int> &temp =  Map[a][s] ;
     if(temp.empty()) cout<<"Not Found\n";
     else for(auto i : temp)  printf("%07d\n",i);
  }
  return 0;
}