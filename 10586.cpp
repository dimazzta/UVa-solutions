#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	while (cin >> n >> k, n != -1) {
		vi c(n + 1);
		for (int i = 0; i < n + 1; i++) {
			cin >> c[i];
		}

		for (int i = n; i - k >= 0; i--) {
			c[i - k] -= c[i];
			c[i] = 0;
		}

		bool all_zero = true;
		for (int i = 0; i <= n; i++) {
			all_zero &= (c[i] == 0);
		}
		if (all_zero) cout << 0 << endl;
		else
		{
			cout << c[0];
			for (int i = 1; i < min(n + 1, k); i++) {
				cout << " ";
				cout << c[i];
			}
			cout << endl;
		}
	}
	return 0;
}


