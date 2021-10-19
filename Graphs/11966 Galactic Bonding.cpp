#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e3 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, nSets, parent[N], sz[N];
double d, x[N], y[N];

void init() {
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
    nSets = n;
}

int findParent(int u) {
    return (u == parent[u] ? u : parent[u] = findParent(parent[u]));
}

void join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    parent[a] = b;
    nSets--;
}

double dist(int i, int j) {
    double t1 = x[i] - x[j];
    double t2 = y[i] - y[j];
    double ans = sqrt(t1 * t1 + t2 * t2);
    return ans;
}


int main() {
//    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int tc = 1;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        scanf("%d %lf", &n, &d);
        init();
        for (int j = 0; j < n; ++j) {
            scanf("%lf %lf", &x[j], &y[j]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dist(i, j) <= d)
                    join(i, j);
            }
        }
        printf("Case %d: %d\n", t, nSets);
    }


    return 0;
}
