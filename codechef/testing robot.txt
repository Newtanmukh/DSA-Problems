#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x;
		cin >> n >> x;
		char a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		set<int> s;
		s.insert(x);
		for (int i = 0; i < n; i++) {
			if (a[i] == 'L') {
				x--;
			} else {
				x++;
			}
			s.insert(x);
		}
		cout << (int) s.size() << '\n';
	}
	return 0;
}
