#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int a, b;
int parent[N], sz[N];

void init() {
    iota(parent, parent + N, 0);
    fill(sz, sz + N, 1);
}

int findParent(int u) {
    return u == parent[u] ? u : parent[u] = findParent(parent[u]);
}

bool canJoin(int a, int b) {
    a = findParent(a), b = findParent(b);
    if (a == b) return 0;
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    parent[a] = b;
    return 1;
}

int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (~scanf("%d", &a)) {
        init();
        int cnt = 0;
        scanf("%d", &b);
        canJoin(a, b);
        while (scanf("%d", &a), a != -1) {
            scanf("%d", &b);
            if (!canJoin(a, b))
                cnt++;
            if (a == -1) break;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
