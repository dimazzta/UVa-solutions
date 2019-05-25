#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n;
	int t = 1;
	while (cin >> n) {
		if (n == 0) break;
		vector<int> a(n);
		cout << "Case " << t++ << ":" << endl;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		set<int> sums;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					sums.insert(a[i] + a[j]);
				}
			}
		}
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int q; cin >> q;
			auto cs = sums.lower_bound(q);
			int ans = 0;
			if (cs == sums.end()) {
				ans = *sums.rbegin();
			}
			else {
				if (cs != sums.begin()) {
					auto ni = cs; 
					advance(ni, -1);
					if (abs(q - *cs) < abs(q - *ni)) {
						ans = *cs;
					}
					else {
						ans = *ni;
					}
					
				}
				else {
					ans = *cs;
				}
			}
			cout << "Closest sum to " << q << " is " << ans << "." << endl;
		}
	}

}
