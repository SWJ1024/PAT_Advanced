#include<bits/stdc++.h>
using namespace std;

const int inf = 999999;

string female_id, male_id, female_name, male_name;
int female_point = -inf, male_point = inf;

int main(){
   int N, point;
   char c;
   string name, id;

   cin >> N;
   while( N-- ){
      cin >> name >> c >> id >> point;
      if( c == 'M' && point < male_point) { male_id = id; male_name = name; male_point = point; }
      else if( c == 'F' && point > female_point) { female_id = id; female_name = name; female_point = point; }
   }
   bool ok = true;
   if(female_point == -inf) { cout << "Absent\n"; ok = false; }
   else cout << female_name << " " << female_id <<endl;
   if(male_point == inf) { cout << "Absent\n";  ok = false; }
   else  cout << male_name << " " << male_id <<endl;

   if(ok) cout << female_point - male_point << endl;
   else cout<<"NA\n";
   return 0;
}