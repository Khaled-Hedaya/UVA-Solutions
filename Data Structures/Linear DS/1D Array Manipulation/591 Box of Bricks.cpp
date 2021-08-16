#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long

const int N = 2e5 + 10 , OO = 0x3f3f3f3f;

int h[101];

int main()
{

	int n, tc = 1;
	while (cin >> n , n != 0) {
		int sum = 0, ans = 0, mid = 0;
		for (int i = 0 ; i < n ; ++i) {
			cin >> h[i];
			sum += h[i] ;
		}
		mid = sum / n;
		for (int i = 0 ; i < n ; ++i)
			if ((h[i] - mid) > 0)
				ans += (h[i] - mid);

		cout << "Set #" << tc << endl << "The minimum number of moves is " << ans << "." << "\n" << "\n";
		++tc;
	}


	return 0;
}
