#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 205, OO = 0x3f3f3f3f, M = 2e5 + 10;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, cost, sorted[M], mn, src, dest;
pair<int, int> dfs_parent[N];
char st[105], tt[105];
vector<pair<int, int>> adj[N];

struct edge {
    int f, t, c;

    bool operator<(const edge &e) const {
        return c > e.c;
    }
} edges[M];

int parent[N], sz[N], nSets;

struct DSU {
    void init() {
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
        a = findParent(a), b = findParent(b);
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        parent[a] = b;
        nSets--;
    }
};

void dfs(int u, int p) {
    for (auto ch: adj[u]) {
        int v = ch.first;
        if (v != p) {
            dfs_parent[v] = {u, ch.second};
            dfs(v, u);
        }
    }
}

void getPath(int tr) {
    int x = tr;
    for (; x != src; x = dfs_parent[x].first) {
        mn = min(mn, dfs_parent[x].second);
    }

}

int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int tc = 0;
    while (scanf("%d %d", &n, &m), n || m) {
        map<string, int> mp;
        int idx = 0;
        DSU ds;
        ds.init();
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        mn = OO;
        for (int i = 0; i < m; ++i) {
            scanf("%s %s %d", st, tt, &cost);
            if (mp.find(st) == mp.end())
                mp[st] = idx++;
            if (mp.find(tt) == mp.end())
                mp[tt] = idx++;
            edges[i].f = mp[st];
            edges[i].t = mp[tt];
            edges[i].c = cost;
            sorted[i] = i;
        }
        scanf("%s %s", st, tt);
        src = mp[st];
        dest = mp[tt];

        sort(sorted, sorted + m, [](int &a, int &b) {
            return edges[a] < edges[b];
        });
        for (int i = 0; i < m; ++i) {
            int cur_idx = sorted[i];
            int f = edges[cur_idx].f;
            int t = edges[cur_idx].t;
            int c = edges[cur_idx].c;
            if (ds.sameSet(f, t))
                continue;
            ds.join(f, t);
            adj[f].emplace_back(t, c);
            adj[t].emplace_back(f, c);
        }
        dfs(src, -1);
        getPath(dest);
        printf("Scenario #%d\n", ++tc);
        printf("%d tons\n\n", mn);
    }


    return 0;
}
