#include <set>
#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;
set<int> st[55];
int main()
{
    int n, tn, t, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &tn);
        while (tn--){
            scanf("%d", &t);
            st[i].insert(t);
        }
    }
    scanf("%d", &n);
    while (n--){
        scanf("%d%d", &a, &b);
        vector<int> total, same;
        set_union(st[a].begin(), st[a].end(), st[b].begin(), st[b].end(), back_inserter(total));
        set_intersection(st[a].begin(), st[a].end(), st[b].begin(), st[b].end(), back_inserter(same));
        printf("%.1f%%\n", 100.0*same.size()/total.size());
    }
    return 0;
}