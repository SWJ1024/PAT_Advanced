#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;
vector<int> post, in;
int n, root;
int fa[MAXN], child[MAXN][2];
bool full = true;

int get_height(int x) {
    int cnt = 0;
    while (x != -1) {
        x = fa[x];
        cnt++;
    }
    return cnt;
}


void build(int inl, int inr, int postr, int father) {
    if (inl > inr) return;
    int i = inl;
    while (in[i] != post[postr]) i++;
    if (father == -1) root = in[i];
    fa[ in[i] ] = father;
    int l = postr+i-inr-1, r = postr-1;
    if ((inl <= i-1 && i+1 > inr) || (inl > i-1 && i+1 <= inr) ) full = false;
    if (inl <= i-1) child[in[i]][0] = post[l];
    if (i+1 <= inr) child[in[i]][1] = post[r];
    build(inl, i-1, l, in[i]);
    build(i+1, inr, r, in[i]);
}

int main() {
    for (int i = 0; i < MAXN; i++) fa[i] = i ;
    cin >> n;
    post.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    
    build(0, n-1, n-1, -1);

    int Q;
    cin >> Q;
    getchar();
    while (Q--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        if (s[s.length()-1] == 't' ) {
	int k;
	ss >> k;
	if (k == root) cout << "Yes\n";
	else cout << "No\n";
        }
        else if (s[s.length()-1] == 's' ) {
	int l, r;
	ss >> l; ss >> s; ss >> r;
	if (fa[l] == fa[r]) cout << "Yes\n";
	else cout << "No\n";
        }
        else if (s[s.length()-1] == 'l' ) {
	int l, r;
	ss >> l; ss >> s; ss >> r;
	int len1 = get_height(l);
	int len2 = get_height(r);
	if (len1 == len2) cout << "Yes\n";
	else cout << "No\n";
         }
         else if (s[s.length()-1] == 'e' ) {
	if(full)  cout << "Yes\n";
	else cout << "No\n";
          }
         else {
	int l, r;
	ss >> l; 
	ss >> s; ss >> s; ss >> s;
	if (s[0] == 'p') {
	     ss >> s; ss >> r;
	     if (fa[r] == l) cout << "Yes\n";
    	     else cout << "No\n";
	} 
	else if (s[0] == 'l') {
                     ss >> s; ss >> s; ss >> r;
  	     if(child[r][0] == l) cout << "Yes\n";
    	     else cout << "No\n";
	}
	else {
	     ss >> s; ss >> s; ss >> r;
	     if(child[r][1] == l) cout << "Yes\n";
  	     else cout << "No\n";
	}
          }
     }
     return 0;
}