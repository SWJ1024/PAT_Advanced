#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
unordered_map< string, int > SchoolCache;
int Count = 0;

struct node{
   string school;
   int cnt, pos, mark;
   double Mark;
   bool operator < (const node &rhs) const {
      if( mark != rhs.mark) return mark > rhs.mark;
      if(cnt != rhs.cnt) return cnt < rhs.cnt;
      return school < rhs.school;
   }
}v[MAXN];

int getid(string &school){
   for(auto &i : school)  if( isupper(i) )  i = tolower(i);
   if( !SchoolCache.count( school) ) SchoolCache[ school ] = Count++;
   return SchoolCache[ school ];
}

int main(){
   int N, score;

   cin >> N;
   getchar();
   for(int i = 0; i < N; i++){
      char id[10], s[10];
      scanf("%s%d%s", id, &score, s);
      string school(s);
      node &t = v[ getid( school ) ];
      t.school = school;
      t.cnt++;
      if(id[0] == 'A') t.Mark += score;
      else if(id[0] == 'T') t.Mark += (score*1.5);
      else t.Mark += (score/1.5);
   }
   for(int i = 0; i < Count; i++) v[i].mark = (int)v[i].Mark;
   sort(v, v+Count);
   cout << Count << endl;
   for(int i = 0; i < Count; i++){
      if( i && v[i].mark == v[i-1].mark)   v[i].pos = v[i-1].pos;
      else v[i].pos = i+1;
      printf("%d %s %d %d\n", v[i].pos, v[i].school.c_str(), v[i].mark, v[i].cnt);
   }
   return 0;
}