#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<bool> v(n, false);
		int last = 0;
		int curr = 0;
		for (int i = 0; i < n; i++) {
			cin >> curr;
			if (i != 0) {
				int diff = abs(curr - last);
				if (diff <= n - 1) v[diff] = true;
			}
			last = curr;
		}
		bool jolly = true;
		for (int i = 1; i < n; i++) {
			if (!v[i]) {
				jolly = false;
				break;
			}
		}
		if (jolly) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
}
