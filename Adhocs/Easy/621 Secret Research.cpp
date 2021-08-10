#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
#define F first
#define S second
#define pb push_back
#define ll long long
#define All(v) v.begin() , v.end()
#define rep(i,s,e) for (int i = s; i < e; ++i)
#define repr(i,s,e) for (int i = s; i > e; --i)


const int N = 1e5 + 10, OO = 0x3f3f3f3f;

bool checkPos(string now) {
    if (now == "1" || now == "4" || now == "78")
        return 1;
    return 0;
}

bool checkNeg(string now) {
    int len = now.size();
    if (now[len - 1] != '5' || now[len - 2] != '3') return 0;
    return 1;
}
bool checkFail(string now) {
    int len = now.size();
    if (now[len - 1] != '4' || now[0] != '9') return 0;
    return 1;
}

bool checkNot(string now) {
    int len = now.size();
    if (now[0] != '1' || now[1] != '9' || now[2] != '0') return 0;
    return 1;
}

int main()
{

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        if (checkPos(s)) cout << "+";
        else if (checkNeg(s)) cout << "-";
        else if (checkFail(s)) cout << "*";
        else if (checkNot(s)) cout << "?";
        else cout << "+";
        cout << "\n";
    }



    return 0;
}




