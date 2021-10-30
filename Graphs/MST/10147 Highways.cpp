#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e3 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int tc, x[N], y[N];

struct edge {
    int c, f, t;

    bool operator<(const edge &e) const {
        return c < e.c;
    }
};

struct DSU {
    int parent[N], sz[N], nSets;

    void init(int n) {
        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);
        nSets = n;
    }

    int findParent(int u) {
        return u == parent[u] ? u : parent[u] = findParent(parent[u]);
    }

    bool sameSet(int a, int b) {
        return findParent(a) == findParent(b);
    }

    void join(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        parent[a] = b;
        sz[b] += sz[a];
        nSets--;
    }

};

int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d", &tc);
    int pp = 1;
    while (tc--) {
        if (!pp)
            puts("");
        pp = 0;
        int n;
        scanf("%d", &n);
        DSU d;
        d.init(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", x + i, y + i);
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            --a, --b;
            d.join(a, b);
        }
        if (d.nSets == 1) {
            puts("No new highways need");
            continue;
        }
        vector<edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);;
                edges.push_back({c, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int sz = (int) edges.size();
        for (int i = 0; i < sz; ++i) {
            int f = edges[i].f;
            int t = edges[i].t;
            if (d.sameSet(f, t))
                continue;
            d.join(f, t);
            printf("%d %d\n", f + 1, t + 1);
        }
    }


    return 0;
}
