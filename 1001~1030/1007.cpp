#include<bits/stdc++.h>
using namespace std;

const int inf = 9999999;
int N, a;
int maxsum, tempsum = 0, i, j, i1;
int Start, End;

int main(){
   maxsum = -inf;
   cin >> N;
   for(int k = 0; k < N; k++){
      scanf("%d",&a);
      if( !k )  Start = a; 
      if( k == N-1) End = a;
      if( !tempsum ) i1 = a;
      tempsum += a;
      if( tempsum > maxsum ){
         i = i1; j = a; maxsum = tempsum;
      }
      if( tempsum <= 0 ) tempsum = 0;
      
   }
   if(maxsum >= 0) cout<<maxsum<<" "<<i<<" "<<j<<endl;
   else cout<<"0 "<<Start<<" "<<End<<endl;
   return 0;
}