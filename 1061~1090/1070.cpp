#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000+5;
int N, D;
struct node{
   double amount, price, average;
   bool operator < (const node &rhs) const{
     return average > rhs.average;
   }
}a[ MAXN ];


int main(){
   cin >> N >> D;
   for(int i = 0; i < N; i++) scanf("%lf", &a[i].amount);
   for(int i = 0; i < N; i++){
      scanf("%lf", &a[i].price);
      a[i].average = a[i].price / a[i].amount;
   }
   sort(a, a+N);
   double sum = 0.0;
   for(int i = 0; i < N && D > 0; i++){
      if( D > a[i].amount ) {
         sum += a[i].price;
         D -= a[i].amount;
      }
      else{
         sum += ( (D*a[i].average) );
         D = 0;
      }
   }
   printf("%.2f\n", sum);
   return 0;
}