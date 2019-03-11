#include<bits/stdc++.h>
using namespace std;

struct node{
   char id[20];
   int point;
   bool operator < (const node &rhs) const {
       if (point != rhs.point) return point > rhs.point;
      else return strcmp(id, rhs.id) < 0;
   }
};

struct stu{
   int a, b;
   bool operator < (const stu &rhs) const {
      if (b != rhs.b) return b > rhs.b;
      else return a < rhs.a;
   }
};

map<char, int> NameCache{{'T', 0}, {'A', 1}, {'B', 2}};
unordered_map<int, pair<int, int>> m;
unordered_map<int, unordered_map<int, int> > My_map;
vector<node> v[3]; 
int cnt = 0;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    node t;
    while (N--) {
       scanf("%s%d", t.id, &t.point);
       // type 1
       v[NameCache[t.id[0]]].push_back(t);
       // type 2 
       int k = 0, l = 0;
       for (int i = 1; i < 4; i++) k = k*10 + (t.id[i]-'0');
       m[k].first++; 
       m[k].second += t.point;
       // type 3 
       for (int i = 4; i < 10; i++) l = l*10 + (t.id[i]-'0');
       unordered_map<int, int> &t = My_map[l];
       t[k]++;
    }
    
    for (int i = 0; i < 3; i++) sort(v[i].begin(), v[i].end());
    
    
    for (int t = 1; t <= M; t++) {
        int type;
        char s[20];
        scanf("%d%s", &type, s);
        printf("Case %d: %d %s\n", t, type, s);
        switch(type) {
           case 1 : {
              vector<node> &t = v[NameCache[s[0]]];
              if (t.empty()) cout << "NA\n";
              else for (auto &i : t)     printf("%s %d\n", i.id, i.point);
              break;
          }
          case 2 : {
              int k = 0;
              for (int i = 0; i < 3; i++) k = k*10 + (s[i]-'0');
              if (!m.count(k)) cout << "NA\n";
              else printf("%d %d\n", m[k].first, m[k].second);
              break;
           }
           case 3 : {
              int l = 0;
              for (int i = 0; i < 6; i++) l = l*10 + (s[i]-'0');
              unordered_map<int, int> &t = My_map[l];
              if (t.empty()) cout << "NA\n";
              else {
                 vector<stu> temp;
                 for (auto &it : t)  temp.push_back({it.first, it.second});
                 sort(temp.begin(), temp.end());
                 for (auto &i : temp)  printf("%d %d\n", i.a, i.b);
              }
              break;
           }
        }
      }
      return 0;
}
