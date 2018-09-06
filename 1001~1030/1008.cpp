#include<bits/stdc++.h>
using namespace std;

int main(){
   int N, sum, past = 0, cur;
   cin >> N;
   sum = 5*N;
   for(int i = 0; i < N; i++){
      cin >> cur;
      sum += ( (cur > past ? 6: 4)*abs(cur-past) );
      past = cur;
   }
   cout<<sum<<endl;
   return 0;
}