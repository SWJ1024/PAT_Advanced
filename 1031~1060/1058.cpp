#include<bits/stdc++.h>
using namespace std;



int main(){
   int a, b, c, a1, b1, c1, B, A;
   scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &a1, &b1, &c1);
   B = (c + c1) / 29;
   c = (c + c1) % 29;
   A = (b + b1 + B) / 17;
   b = (b + b1 + B) % 17;
   a = a + a1 + A;
   printf("%d.%d.%d\n", a, b, c);
   return 0;
}