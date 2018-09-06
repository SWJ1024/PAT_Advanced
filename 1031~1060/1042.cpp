#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
char s[55][4]={"","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                   "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                   "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                   "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
                   "J1","J2"};
int card[55][2], a[55];


int main(){
    int N, t = 0;
    cin >> N;
    for(int i = 1; i <= 54; i++) scanf("%d", &a[ card[i][0] = i]);
    while( N-- ){
       for(int i = 1; i <= 54; i++)
           card[ a[i] ][ t^1 ] = card[i][t];
       t ^= 1;
    }
    for(int i = 1; i <= 54; i++){
        if(i == 1) printf("%s", s[ card[i][t] ]);
        else printf(" %s", s[ card[i][t] ] );
    }
    return 0;
}