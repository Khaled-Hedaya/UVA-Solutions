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

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<int> seq(n);
    seq[0] = 1, seq[1] = 2, seq[2] = 3;
    int sum = 6;
    for (int i = 3; i < n; ++i) {
        int cur = (sum % m) + 1;
        seq[i] = cur;
        sum -= seq[i - 3];
        sum += cur;
    }
    //db(seq);
    int l, r, ans = OO;
    l = r = 0;
    map<int, int> freq;
    int cnt = 0;
    while (l < n) {
        while (r < n && cnt < k) {
            int e = seq[r++];
            freq[e]++;
            if (e <= k && freq[e] == 1)
                cnt++;
        }
        if (cnt == k)
            ans = min(ans, r - l);
        if (seq[l] <= k && freq[seq[l]] == 1)
            cnt--;
        freq[seq[l]]--;
        l++;
    }
    if (ans == OO) cout << "sequence nai\n";
    else cout << ans << "\n";
}

int main() {

    FastIO();
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        solve();
#ifdef ONPC
        cout << "__________________________" << "\n";
#endif
    }

    return 0;
}
