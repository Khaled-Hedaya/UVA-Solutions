#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const int OO = 0x3f3f3f3f, N = 2e3 + 10;


vector<int> adj[N], adjR[N];
stack<int> nodes;
int compId[N], vis[N], vid, n, m, cntComp, tc, x[N], y[N], d[N];
int notSrc[N], notSnk[N];

void dfs1(int u) {
    if (vis[u] == vid) return;
    vis[u] = vid;
    for (auto v: adj[u]) {
        dfs1(v);
    }
    nodes.push(u);
}

void dfs2(int u, int id) {
    if (vis[u] == vid) return;
    vis[u] = vid;
    compId[u] = id;
    for (auto v: adjR[u]) {
        dfs2(v, id);
    }
}


void Kusoraju() {
    ++vid;
    for (int i = 0; i < n; ++i) {
        if (vis[i] != vid) {
            dfs1(i);
        }
    }
    ++vid;
    cntComp = 0;
    while (!nodes.empty()) {
        int u = nodes.top();
        nodes.pop();
        if (vis[u] == vid) continue;
        dfs2(u, cntComp++);
    }
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < (int) adj[u].size(); ++i) {
            int v = adj[u][i];
            if (compId[u] == compId[v])
                continue;
            notSrc[compId[v]] = vid;
            notSnk[compId[u]] = vid;
        }
    }

}


bool isContain(int i, int j) {
    return (2 * abs(x[i] - x[j]) <= d[i] && 2 * abs(y[i] - y[j]) <= d[i]);
}

void clear() {
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        adjR[i].clear();
    }
    while (!nodes.empty())
        nodes.pop();
}

int main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("in.txt", "r", stdin);
    scanf("%d", &tc);
    while (tc--) {
        clear();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", x + i, y + i, d + i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isContain(i, j))
                    adj[i].push_back(j), adjR[j].push_back(i);
                if (isContain(j, i))
                    adj[j].push_back(i), adjR[i].push_back(j);
            }
        }
        Kusoraju();
        int cntSrc = cntComp - count(notSrc, notSrc + cntComp, vid);
        printf("%d\n", cntSrc);


    }

    return 0;
}
