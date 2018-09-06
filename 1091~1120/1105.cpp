#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000+5;
vector < int > v;
int a[MAXN][MAXN],N, x = 0, y = 0, i = 0;

void Print(int w1, int w2, int w3, int w4, int flag){
   if(i >= N-1) return;
   if(flag==1){
        while(x != w2) a[x++][y] = v[i++];
        Print(w1+1, w2, w3, w4,2);
   }
   else if(flag==2){
        while(y != w3) a[x][y++] = v[i++];
        Print(w1 ,w2-1, w3, w4,3);
   }
   else if(flag == 3){
        while(x != w4) a[x--][y] = v[i++];
        Print(w1, w2, w3-1, w4,4);
   }
   else{
        while(y != w1) a[x][y--] = v[i++];
        Print(w1, w2, w3, w4+1, 1);
   }
}

bool cmp(int a, int b){ return a > b; }

int main(){
   cin>>N;
   for(int i = 0; i < N; i++){
      int x;
      scanf("%d", &x);
      v.push_back(x);
   }
   sort(v.begin(), v.end(), cmp);
   int m, n = sqrt(N);
   while(1){
       if(N % n == 0){
          m = N / n;
          break;
       }
       n--;
   }
   Print(0, n-1, m-1, 0, 1);
   a[x][y] = v[i];
   for(int y = 0; y < m; y++)
     for(int x = 0;x < n; x++)
        cout << a[x][y] << ( (x == n-1)? '\n' : ' ');
   return 0;
}
