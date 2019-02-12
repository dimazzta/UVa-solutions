#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		int a = 0, b = 0;
		bool turn = true;
		for (int i = 0; i < 32; i++) {
			int k = (n & (1 << i));
			if (k)
			{
				if (turn) {
					a += k;
				}
				else {
					b += k;
				}
				turn = !turn;
			}
		}

		cout << a << " " << b << endl;
	}
}
