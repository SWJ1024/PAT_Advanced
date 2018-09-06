#include<bits/stdc++.h>
using namespace std;


const int MAXN = 1e5 + 10;

int fd[MAXN];
bool visit[MAXN];

int main(){
   int N, sum = 0;
   cin>>N;
   for(int i = 0; i < N; i++) scanf("%d", &fd[i]);
   for(int i = 0; i < N; i++){
     if( !visit[i] ){
        int root = i, cnt = 0;
        do{
            visit[i] = true;
            i = fd[i];
            cnt++;
        }while(i != root);
        if( cnt == 1) ;
        else if( !i ) sum += cnt - 1;
        else sum += cnt + 1;
     }
  }
  cout << sum << endl;
  return 0;
}