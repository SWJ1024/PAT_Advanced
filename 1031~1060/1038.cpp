#include<bits/stdc++.h>
using namespace std;

int N;
string s;
vector< string > v;
bool cmp (string a, string b){
  return a + b < b +a;
}

int main(){
   cin >> N;
   v.resize(N);
   for(int i = 0; i < N; i++)  cin >> v[i];
   sort(v.begin(), v.end(), cmp);
   string sum;
   for(auto i : v) sum += i;
   int len = sum.length(), start = 0;
   for(; start < len; start++)
      if(sum[start] != '0') break;
   if( start == len ) cout << "0\n";
   else for(int i = start; i < len; i++)
     cout<< sum[i];
   return 0;
}