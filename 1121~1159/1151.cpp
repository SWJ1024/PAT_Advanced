#include<bits/stdc++.h>
using namespace std;

vector<int> fa(1e6);

void f(int inl, int inr, int prel, vector<int> &in, vector<int> &pre) {
   if (inl > inr) return;
   int i = inl;
   while (in[i] != pre[prel]) i++;
   int l = prel+1, r = i+1+prel-inl;
   if (inl <= i-1) fa[pre[l]] = in[i];
   if (i+1 <= inr) fa[pre[r]] = in[i];
   f(inl, i-1, l, in, pre);
   f(i+1, inr, r, in, pre);	
}

int get_dist(int x) {
   int cnt = 0;
   while (x != fa[x]) {
      x = fa[x];
      cnt++;
   }
   return cnt;
}

void up(int &x, int cnt) {
   while (cnt--) x = fa[x];
}


int main() {
   int N, M;
   scanf("%d%d", &M, &N);
   unordered_set<int> My_set;
   vector<int> pre(N), in(N);
   for (int i = 1; i <= N; i++) fa[i] = i;
   for (int i = 0; i < N; i++) scanf("%d", &in[i]);
   for (int i = 0; i < N; i++) {
      scanf("%d", &pre[i]);
      My_set.insert(pre[i]);
   }
   f(0, N-1, 0, in, pre);
	
   while (M--) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (!My_set.count(a)) {
      if (!My_set.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
      else printf("ERROR: %d is not found.\n", a);
   }
   else {
      if (!My_set.count(b)) printf("ERROR: %d is not found.\n", b);
      else {
         int A = a, B = b;
         int len1 = get_dist(a), len2 = get_dist(b);
         if (len1 > len2) up(a, len1-len2);
         else if (len1 < len2) up(b, len2-len1);
         while (a != fa[a] && a != b) {
            a = fa[a];
            b = fa[b];
         }
         if (a == B) printf("%d is an ancestor of %d.\n", B, A);
         else if (a == A) printf("%d is an ancestor of %d.\n", A, B);
         else printf("LCA of %d and %d is %d.\n", A, B, a);
         }
      }
   }
   return 0;
}
