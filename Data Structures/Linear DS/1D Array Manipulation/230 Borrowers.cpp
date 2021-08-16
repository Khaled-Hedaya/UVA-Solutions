#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
#define F first
#define S second
#define SZ(v) (int)v.size()
#define All(v) v.begin() , v.end()


const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*

"Maybe they aren't stars.. Maybe they are a map to get out of here"

*/

int main() {

    FastIO()

    string line, author, title;

    vector<pair<string, string> > books; // author , title

    while (getline(cin, line), line != "END") {
        istringstream ss(line);
        ss.ignore(1, '"');
        getline(ss, title, '"');
        ss.ignore(4);
        getline(ss, author);
        books.push_back({author, title});
    }

    sort(All(books));


    map<string, int> mp; // title , id
    int sz = SZ(books);
    for (int i = 0; i < sz; ++i) {
        mp[books[i].S] = i;
    }

    vector<bool> borrowed(sz);
    vector<bool> returned(sz);


    line = "";

    while (getline(cin, line), line != "END") {
        istringstream ss(line);
        int prv_id = -1;
        ss.ignore(8);
        getline(ss, title, '"');

        if (line[0] == 'B') {
            borrowed[mp[title]] = 1;
            returned[mp[title]] = 0;
        } else if (line[0] == 'R') {
            borrowed[mp[title]] = 0;
            returned[mp[title]] = 1;
        } else {
            for (int i = 0; i < sz; ++i) {
                if (returned[i]) {
                    if (prv_id != -1)
                        cout << "Put \"" << books[i].S << '"' << " after " << '"' << books[prv_id].S << '"' << "\n";
                    else
                        cout << "Put \"" << books[i].S << '"' << " first\n";
                    returned[i] = borrowed[i] = 0;
                    prv_id = i;
                } else if (!borrowed[i])
                    prv_id = i;
            }
            cout << "END\n";
        }

    }


    return 0;
}
