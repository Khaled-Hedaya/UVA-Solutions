#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 2e3 + 10, OO = 0x3f3f3f3f, M = 5e4 + 10;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int tc;
char s[10], t[10];
int sorted[M], from[M], to[M], cst[M];

struct DSU {
    int parent[N], sz[N], nSets;

    void init(int n) {
        iota(parent, parent + n + 1, 0);
        fill(sz, sz + n + 1, 1);
        nSets = n;
    }

    int findParent(int u) {
        return u == parent[u] ? u : parent[u] = findParent(parent[u]);
    }

    bool join(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b) return 0;
        if (sz[a] > sz[b]) swap(a, b);
        parent[a] = b;
        sz[b] += sz[a];
        nSets--;
        return 1;
    }
};


int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int n, m, c;
    scanf("%d", &tc);
    int pp = 1;
    while (tc--) {
        if (!pp) puts("");
        pp = 0;
        scanf("%d %d", &n, &m);
        DSU d;
        d.init(n);
        int idx = 0;
        map<string, int> mp;
        for (int i = 0; i < m; ++i) {
            scanf("%s %s %d", s, t, &c);
            if (mp.find(s) == mp.end())
                mp[s] = idx++;
            if (mp.find(t) == mp.end())
                mp[t] = idx++;
            from[i] = mp[s];
            to[i] = mp[t];
            cst[i] = c;
            sorted[i] = i;
        }
        sort(sorted, sorted + m, [](const int a, const int b) {
            return cst[a] < cst[b];
        });
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            int cur_idx = sorted[i];
            if (d.join(from[cur_idx], to[cur_idx]))
                ans += cst[cur_idx];
        }
        printf("%lld\n", ans);
    }


    return 0;
}
