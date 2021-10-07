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

const int N = 2e3 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, e, vis[N], vid, cntComp, compId[N];
vector<int> adj[N], adjR[N];
stack<int> nodes;

void dfs1(int src) {
    vis[src] = vid;
    for (auto v: adj[src]) {
        if (vis[v] != vid)
            dfs1(v);
    }
    nodes.push(src);
}

void dfs2(int src, int id) {
    vis[src] = vid;
    compId[src] = id;
    for (auto v: adjR[src])
        if (vis[v] != vid)
            dfs2(v, id);
}

void kosaraju() {
    vid++;
    for (int i = 0; i < n; ++i)
        if (vis[i] != vid)
            dfs1(i);

    vid++;
    cntComp = 0;
    while (!nodes.empty()) {
        int u = nodes.top();
        nodes.pop();
        if (vis[u] == vid) continue;
        dfs2(u, cntComp++);
    }

}


void solve() {
    for (int i = 0; i < e; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        --a, --b;
        adj[a].push_back(b);
        adjR[b].push_back(a);
        if (v == 2)
            adj[b].push_back(a), adjR[a].push_back(b);
    }

    kosaraju();

    if (cntComp == 1) cout << "1\n";
    else cout << "0\n";
}

int main() {

    FastIO();
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    // cin >> tc;
    while (cin >> n >> e, n || e) {
        for (int i = 0; i < N; ++i)
            adjR[i].clear(), adj[i].clear();
        while (!nodes.empty())
            nodes.pop();
        memset(compId, 0, sizeof compId);
        solve();
#ifdef ONPC
        cout << "__________________________" << "\n";
#endif
    }

    return 0;
}
