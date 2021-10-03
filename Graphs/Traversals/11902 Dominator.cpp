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

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n;
vector<int> adj[105];
int canReach[105];

void dfs1(int src) {
    canReach[src] = 1;
    for (auto ch: adj[src])
        if (!canReach[ch])
            dfs1(ch);
}

void dfs2(int src, int toIgnore, vector<bool> &v) {
    v[src] = 0;
    for (auto ch: adj[src]) {
        if (ch != toIgnore && v[ch])
            dfs2(ch, toIgnore, v);
    }
}

void Print(int x) {
    x = x * 2 - 1;
    cout << '+';
    for (int i = 0; i < x; ++i)
        cout << '-';
    cout << "+\n";
}


void solve() {
    memset(canReach, 0, sizeof canReach);
    for (int i = 0; i < 105; ++i) {
        adj[i].clear();
    }
    cin >> n;
    vector<vector<bool>> dom(n, vector<bool>(n, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x) adj[i].pb(j);
        }
    }
    dfs1(0);
    for (int ign = 1; ign < n; ++ign) {
        dfs2(0, ign, dom[ign]);
    }
    Print(n);
    for (int i = 0; i < n; ++i) {
        cout << '|';
        for (int j = 0; j < n; ++j) {
            if (dom[i][j] && canReach[j])
                cout << "Y|";
            else
                cout << "N|";
        }
        cout << "\n";
        Print(n);
    }

}

int main() {

    FastIO();
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ":\n";
        solve();
#ifdef ONPC
        cout << "__________________________" << "\n";
#endif
    }

    return 0;
}
