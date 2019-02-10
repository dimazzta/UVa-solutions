#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		cout << (b ^ (b >> 1)) << endl;
	}
}
