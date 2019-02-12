#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, r;
	while (scanf("%d %d", &s, &r), s || r) {
		int a, b;
		bitset<1000001> bs;
		bs.reset();
		bool confl = false;
		for (int i = 0; i < s; i++) {
			int a, b;
			cin >> a >> b;
			if (!confl)
				for (int j = a; j < b; j++) {
					if (bs[j]) confl = true;
					else bs.set(j);
				}
		}

		for (int i = 0; i < r; i++) {
			int a, b, interv;
			cin >> a >> b >> interv;
			int start = 0;
			if (!confl)
				while (start <= 1000000) {
					for (int j = a + start; j < b + start && j <= 1000000; j++) {
						if (bs[j]) confl = true;
						else bs.set(j);
					}
					start += interv;
				}
		}
		confl ? cout << "CONFLICT" << endl : cout << "NO CONFLICT" << endl;
	}
}
