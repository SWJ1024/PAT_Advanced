#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double a;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum = sum + i *(n - i + 1)*a;
    }
    printf("%.2f", sum);
    return 0;
}