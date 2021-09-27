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

int val, ans1, ans2, n;
vector<int> v;

bool ok1(int h) {
    return (v[h] < val);
}

bool ok2(int h) {
    return (v[h] > val);
}

void bs1() { // T T T (T) F F F
    int lo = 0, hi = n - 1, mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (ok1(mid)) {
            ans1 = mid;
            lo = mid;
        } else hi = mid - 1;
    }
    if (ok1(lo))
        ans1 = lo;
}

void bs2() { // F F F (T) T T T
    int lo = 0, hi = n - 1, mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (ok2(mid)) {
            ans2 = mid;
            hi = mid;
        } else
            lo = mid + 1;
    }
    if (ok2(lo))
        ans2 = lo;
}

void solve() {
    cin >> n;
    v.resize(n);
    for (auto &x: v)
        cin >> x;
    int q;
    cin >> q;
    while (q--) {
        cin >> val;
        ans1 = ans2 = -1;
        bs1();
        bs2();
        if (ans1 == -1) cout << "X ";
        else cout << v[ans1] << " ";
        if (ans2 == -1) cout << "X";
        else cout << v[ans2];
        cout << "\n";
    }

}

int main() {

    FastIO();
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
#ifdef ONPC
        cout << "__________________________" << "\n";
#endif
    }

    return 0;
}
