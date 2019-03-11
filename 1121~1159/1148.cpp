#include<bits/stdc++.h>
using namespace std;

int n;
bool check(int i, int j, vector<int> &u) {
    int wolf = 0, man = 0;	
    for (int k = 1; k <= n; k++) {
       if (u[k] > 0 && (u[k] == i || u[k] == j)) {
           if (k == i || k == j) wolf++;
          else man++;
       }
       else if(u[k] < 0 && (u[k] != -i && u[k] != -j)) {
          if (k == i || k == j) wolf++;
          else man++;
       }
    }
   if (wolf == 1 && man == 1) return true;
   else return false;
}

int main() {
   cin >> n;
   vector<int> u(n+1);
   for (int i = 1; i <= n; i++)   scanf("%d", &u[i]);
   
   for (int i = 1; i <= n;i++) {
      for (int j = i+1; j <= n; j++) {
          if (check(i, j, u)) {
              cout << i << " " << j << endl;
              return 0;
          }
      }
   }
   cout << "No Solution\n";
   return 0;
}