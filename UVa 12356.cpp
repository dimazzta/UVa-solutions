#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, b;
	while (scanf("%d %d", &s, &b), s || b) {
		vector<int> vL(s + 1, 0);
		vector<int> vR(s + 1, 0);
		iota(vL.begin() + 1, vL.end(), 0);
		iota(vR.begin() + 1, vR.end() - 1, 2);

		int l, r;
		while (b-- && scanf("%d %d", &l, &r)) {
			int fr = vR[r];
			vL[fr] = vL[l];
			int fl = vL[l];
			vR[fl] = vR[r];

			if (vL[l]) cout << vL[l] << " ";
			else cout << "* ";
			if (vR[r]) cout << vR[r] << endl;
			else cout << "*" << endl;
		}
		cout << "-" << endl;
	}
}
