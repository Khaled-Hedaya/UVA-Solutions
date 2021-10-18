#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 200 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, isBi, col[N];
vector<int> adj[N];

void bfs(int src = 0) {
    queue<int> q;
    q.push(src);
    memset(col, OO, n * sizeof(col[0]));
    col[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (col[v] == OO) {
                col[v] = 1 - col[u];
                q.push(v);
            } else if (col[v] == col[u]) {
                isBi = 0;
                return;
            }
        }
    }
}

int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (scanf("%d", &n), n) {
        isBi = 1;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs();
        puts((!isBi) ? "NOT BICOLORABLE." : "BICOLORABLE.");
    }

    return 0;
}
