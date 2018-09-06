#include<bits/stdc++.h>
using namespace std;

vector <int> pre, post, in;
bool Unique = true;

void inorder(int prel, int prer, int postl, int postr){
   if(prel > prer) return;
   if(prel == prer){
      in.push_back(pre[prel]);
      return;
   }
   int i = prel+1;
   while( pre[i] != post[postr-1] ) i++;
   if(i-prel == 1) Unique = false;
   inorder(prel+1, i-1, postl, i-2-prel+postl);
   in.push_back( post[postr] );
   inorder(i, prer, i-1-prel+postl, postr-1);
}

int main(){
    int n;
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    inorder(0, n-1, 0, n-1);
    printf("%s\n%d", Unique ? "Yes" : "No", in[0]);
    for(int i = 1; i < in.size(); i++)
        cout << " " << in[i];
    putchar('\n');
    return 0;
}