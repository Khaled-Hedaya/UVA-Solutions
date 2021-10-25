#include <bits/stdc++.h>

using namespace std;
#ifdef ONPC
#define db(...) ({cout << "> Line " << __LINE__  \
        << ": "; _db(#__VA_ARGS__, __VA_ARGS__);})
#else
#define db(...) true
#endif

template<class S, class T>
ostream &operator<<(ostream &o, const map<S, T> &v) {
    o << "[";
    int i = 0;
    for (const pair<S, T> &pr: v)
        o << (!i++ ? "" : ", ") << "{"
          << pr.fs << " : " << pr.sc << "}";
    return o << "]";
}

template<template<class, class...> class S, class T, class... L>
ostream &operator<<(ostream &o, const S<T, L...> &v) {
    o << "[";
    int i = 0;
    for (const auto &e: v) o << (!i++ ? "" : ", ") << e;
    return o << "]";
}

template<class S, class T>
ostream &operator<<(ostream &o, const pair<S, T> &pr) {
    return o << "(" << pr.fs << ", " << pr.sc << ")";
}

ostream &operator<<(ostream &o, const string &s) {
    for (const char &c: s) o << c;
    return o;
}

template<class T>
void _db(const char *dbStr, T e) {
    cout << dbStr << " = " << e << endl;
}

template<class T, class... L>
void _db(const char *dbStr, T e, L... r) {
    while (*dbStr != ',') cout << *dbStr++;
    cout << " = " << e << ',';
    _db(dbStr + 1, r...);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FastIO() ios::sync_with_stdio(false), cin.tie(0)
#define F first
#define S second
#define pb push_back
#define ll long long
#define SZ(a) ((int)((a).size()))
#define All(v) v.begin(), v.end()
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define repr(i, s, e) for (int i = s; i > e; --i)

const int N = 2e6 + 10, OO = 0x3f3f3f3f, M = 2e6 + 10;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, u, v, c;
int parent[N], sz[N], sorted[N], from[N], to[N], cst[N], nSets;

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
    if (a == b) return;
    if (sz[a] > sz[b])
        swap(a, b);
    sz[b] += sz[a];
    parent[a] = b;
    nSets--;
}


void solve() {
    init();
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        from[i] = u;
        to[i] = v;
        cst[i] = c;
        sorted[i] = i;
    }
//    sort(edges.begin(), edges.end());
    sort(sorted, sorted + m, [](int &a, int &b) {
        return cst[a] < cst[b];
    });
    int mx = 0;
    for (int i = 0; i < m; ++i) {
        int cur_idx = sorted[i];
        if (sameSet(from[cur_idx], to[cur_idx]))
            continue;
        join(from[cur_idx], to[cur_idx]);
        mx = max(mx, cst[cur_idx]);
    }
    if (nSets == 1)
        printf("%d\n", mx);
    else
        puts("IMPOSSIBLE");
}

int main() {

#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (scanf("%d %d", &n, &m), n || m) {
        solve();
#ifdef ONPC
        puts("-------------------");
#endif
    }

    return 0;
}
