#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, p;
	cin >> t;
	int i = 1;
	while (t--) {
		vector<string> cards(52);
		int x, y = 0;
		for (int i = 0; i < 52; i++) {
			cin >> cards[i];
		}
		p = 26;
		for (int i = 0; i < 3; i++) {
			if (isdigit(cards[p][0])) {
				x = cards[p][0] - '0';
			}
			else {
				x = 10;
			}
			y += x;
			p -= 11 - x;
		}
		int endpoint = p > y ? y : y + 26 - p;
		cout << "Case " << i++ << ": " << cards[endpoint - 1] << endl;
	}
}

