#include <bits/stdc++.h>
using namespace std;


int main() {
	int sz, p;
	while (scanf("%d %d", &sz, &p), sz || p) {
		long long start = 1;

		int h = 1, i = sz / 2 + 1, j = i;

		while (true) {
			i += h;
			start += abs(h);
			if (start >= p) {
				int diff = -start + p;
				if (h < 0) diff *= -1;
				cout << "Line = " << i + diff << ", column = " << j << "." << endl;
				break;
			}
			j -= h;
			start += abs(h);
			if (start >= p) {
				int diff = -start + p;
				if (h > 0) diff *= -1;
				cout << "Line = "  << i << ", column = " << j + diff << "." << endl;
				break;
			}
			
			h *= -1;
			h > 0 ? h++ : h--;
			
		}
	}
}
