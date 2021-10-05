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

const int N = 1e6 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/
vector<int> adj[N];
int n, m;

void solve() {
    for (int i = 0; i < N; ++i)
        adj[i].clear();
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        adj[x].push_back(i + 1);
    }
    while (m--) {
        int k, v;
        cin >> k >> v;
        if ((int) adj[v].size() < k) cout << "0\n";
        else cout << adj[v][k - 1] << "\n";
    }

}

int main() {

    FastIO();
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    // int tc = 1;
    // cin >> tc;
    while (cin >> n >> m) {
        solve();
#ifdef ONPC
        cout << "__________________________" << "\n";
#endif
    }

    return 0;
}
