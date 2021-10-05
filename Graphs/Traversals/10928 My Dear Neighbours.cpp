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

bool comp(pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
    if ((int) a.first.size() < (int) b.first.size()) return 1;
    if ((int) a.first.size() == (int) b.first.size() && a.second < b.second)
        return 1;
    return 0;

}


void solve() {
    int p;
    cin >> p;
    string tmp;
//    getline(cin, tmp);
    cin.ignore();
    vector<pair<vector<int>, int>> dict(p);
    for (int i = 0; i < p; ++i) {
        string l;
        getline(cin, l);
        istringstream ss(l);
        int x;
        vector<int> cur;
        while (ss >> x) {
            cur.push_back(x);
        }
        dict[i] = {cur, i};
    }

    sort(All(dict), comp);

    vector<int> ans;
    pair<vector<int>, int> lst = dict[0];
    ans.push_back(lst.second + 1);
    int idx = 1;
    while (idx < SZ(dict) && (int) dict[idx].first.size() == (int) lst.first.size())
        ans.push_back(dict[idx++].second + 1);
    int sz = SZ(ans);
    for (int i = 0; i < sz; ++i) {
        cout << ans[i] << " \n"[i == sz - 1];
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
        solve();
#ifdef ONPC
        cout << "__________________________" << "\n";
#endif
    }

    return 0;
}
