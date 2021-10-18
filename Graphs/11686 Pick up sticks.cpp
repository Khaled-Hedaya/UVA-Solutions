#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e6 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, vis[N], hasCycle;
vector<int> adj[N], ans;

void dfs(int src) {
    vis[src] = 1; // explored
    for (auto v: adj[src]) {
        if (!vis[v])
            dfs(v);
        else if (vis[v] == 1) {
            hasCycle = 1;
            return;
        }
    }
    vis[src] = 2; // finished
    ans.push_back(src);
}


int main() {
//    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (scanf("%d %d", &n, &m), n || m) {
        hasCycle = 0;
        ans.clear();
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
        }
        for (int i = 1; i <= n; ++i) { // 0: not vistied, 1: explored, 2: finished
            if (!vis[i])
                dfs(i);
        }
        if (hasCycle) puts("IMPOSSIBLE\n");
        else {
            int sz = (int) (ans.size());
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < sz; ++i)
                printf("%d%c", ans[i], " \n"[i == sz - 1]);
        }
    }
    return 0;
}
