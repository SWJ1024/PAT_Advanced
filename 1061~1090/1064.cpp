#include<bits/stdc++.h>
using namespace std;

int N;
vector< int > pre;
vector< vector< int > > H(15);

int Log2(int x){
   return log(x)/log(2)-0.00005;
}


int LeftNum(int N){
   int h = Log2(N+1)+1;
   int n = pow(2, h-2)-1+0.5;
   int Left = N - 2*n - 1;
   return n+min(Left, (int)(pow(2, h-2)+0.5) );
}

void levelorder(int prel, int prer, int height){
   if(prer < prel) return;
   int n = prer-prel+1, L = LeftNum(n), R = n-L;
   H[height].push_back( pre[prel+L] );
   levelorder(prel, prel+L-1, height+1);
   levelorder(prel+L+1,prer, height+1);
}

void print(){
   int cnt = 0, i = 0;
   do{
      for(auto &j : H[i]){
   	 printf("%d", j);
   	 if(++cnt == N) return;
   	 else putchar(' ');
      }
  }while(++i);
}

int main(){
   cin >> N;
   pre.resize(N);
   for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
   sort(pre.begin(), pre.end() );
   levelorder(0, N-1, 0);
   print();
   return 0;
}
