#include<bits/stdc++.h>
using namespace std;

int N;
long long a, b, c, sum;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        bool ok;
        cout << "Case #" << i << ": ";
        cin >> a >> b >> c;
        sum = a + b;
        if( a > 0 && b > 0 && sum <= 0 ) ok = true;
        else if( a < 0 && b < 0 && sum >=0 ) ok = false;
        else if( sum > c ) ok = true;
        else ok = false;
        
        if(ok) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}