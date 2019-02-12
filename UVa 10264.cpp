#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> a(1 << n), pot(1 << n);
		for (int i = 0; i < 1 << n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < n; j++) {
				pot[i] += a[i ^ 1 << j];
			}
		}
		long max = -1;
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < 1 << n; j++) {
				if (i != j && ((i ^ j) & ((i ^ j) - 1)) == 0)
					if (pot[i] + pot[j] > max) max = pot[i] + pot[j];
			}
		}
		cout << max << endl;
	}
}
