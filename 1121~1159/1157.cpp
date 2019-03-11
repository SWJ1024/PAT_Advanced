#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, cnt = 0;
    unordered_set<string> My_set;
    string year1 = "99999999", year2 = "99999999";
    string old1, old2;
    char id[20];
    cin >> n;
    while (n--) {
        scanf("%s", id);
        string s(id);
        My_set.insert(s);
    }
    cin >> n;
    while (n--) {
        scanf("%s", id);
        string s(id);
        string a = s.substr(6, 8);
        if (cnt == 0 && a <= year2) {
            year2 = a;
            old2 = s;
        }
       if (My_set.count(s)) {
           cnt++;
           if (a <= year1) {
               year1 = a;
               old1 = s; 
           }
       }
    }
    if (cnt != 0) cout << cnt << endl << old1 << endl;
    else cout << cnt << endl << old2 << endl;
    return 0;
}