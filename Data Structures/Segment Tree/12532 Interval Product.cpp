#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, q, a[N];
ll seg[4 * N];

void build(int rkmNode = 1, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        seg[rkmNode] = a[ns];
        return;
    }
    int mid = (ns + ne) >> 1, lf = rkmNode << 1, rt = rkmNode << 1 | 1;
    build(lf, ns, mid);
    build(rt, mid + 1, ne);
    seg[rkmNode] = seg[lf] * seg[rt];
}

void update(int qi, int val, int rkmNode = 1, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        seg[rkmNode] = val;
        return;
    }
    int mid = (ns + ne) >> 1, lf = rkmNode << 1, rt = rkmNode << 1 | 1;
    if (qi <= mid)
        update(qi, val, lf, ns, mid);
    else
        update(qi, val, rt, mid + 1, ne);
    seg[rkmNode] = seg[lf] * seg[rt];
}

ll query(int qs, int qe, int rkmNode = 1, int ns = 0, int ne = n - 1) {
    // qs  qe ns , ne
    if (ns >= qs && ne <= qe)
        return seg[rkmNode];
    if (ns > qe || ne < qs)
        return 1LL;
    int mid = (ns + ne) >> 1, lf = rkmNode << 1, rt = rkmNode << 1 | 1;
    return query(qs, qe, lf, ns, mid) * query(qs, qe, rt, mid + 1, ne);
}

int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (~scanf("%d %d", &n, &q)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if (a[i] > 0) a[i] = 1;
            else if (a[i] < 0) a[i] = -1;
        }
        build();
        string ans;
        while (q--) {
            char c;
            int l, r, v;
            scanf(" %c", &c);
            if (c == 'C') {
                scanf("%d %d", &l, &v);
                update(--l, v > 0 ? 1 : v < 0 ? -1 : 0);
            } else { // p
                scanf("%d %d", &l, &r);
                ll cur = query(--l, --r);
                if (cur > 0) ans += '+';
                else if (cur < 0) ans += '-';
                else ans += '0';
            }

        }
        printf("%s\n", ans.c_str());
    }


    return 0;
}
