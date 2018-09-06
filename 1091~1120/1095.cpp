#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000+10, MAXT = 25*60*60+10;
int N, Q, Longest = -1;
set< string > Ansid;


struct node{
   string ID;
   int Time;
   int status;
   bool operator < (const node &rhs) const {
      return (ID != rhs.ID) ? ( ID < rhs.ID ) : ( Time < rhs.Time );
   }
} Record[MAXN];

bool cmp(node a, node b){
	return a.Time < b.Time;
}



int main(){
   cin >> N >> Q;
   for(int i = 0; i < N; i++){
      int hh, mm, ss;
      char id[10], status[5];
      scanf("%s%d:%d:%d%s", id, &hh, &mm, &ss, status);
      Record[i].ID = id;
      Record[i].Time = hh*60*60 + mm*60 + ss;
      Record[i].status = (status[0] == 'i') ? 1 : -1;
   }
   sort( Record, Record+N );
   vector< node > Car;
   string id;
   int Time;

   for(int i = 1; i < N; i++){
       if( Record[i].status == -1 && Record[i-1].status == 1 && Record[i].ID == Record[i-1].ID){
             if(Record[i].ID != id)   Time = 0;
             id = Record[i].ID;
             Time += Record[i].Time - Record[i-1].Time;
             if( Time > Longest ) {
                Ansid.clear();
                Longest = Time;
             }
             if( Time == Longest ) Ansid.insert( id );
             Car.push_back(  Record[i-1] );
             Car.push_back(  Record[i] );
       }
   }
   sort(Car.begin(), Car.end(), cmp);
   int Count = 0, st = 0;
   while( Q-- ){
      int hh, mm, ss, tt, i = st;
      scanf("%d:%d:%d", &hh, &mm, &ss);
      tt = hh*60*60 + mm*60 + ss;
      for(; i < Car.size(); i++){
      	 if( Car[i].Time > tt ) break;
      	 Count += Car[i].status;
      }
      st = i;
      cout << Count << endl;
   }

   for(set< string >::iterator it = Ansid.begin(); it != Ansid.end(); it++) cout << *it <<" ";
   printf("%02d:%02d:%02d\n", Longest/60/60, Longest/60%60, Longest%60);
   return 0;
}