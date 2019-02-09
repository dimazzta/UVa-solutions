#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, p;
	bool endline = false;
	int i = 1;
	while (scanf("%d %d\n", &n, &p), n || p) {
		string s;
		while (n--) {
			getline(cin, s);
		}
		int maxcnt = -1;
		double lowest_price = 2e31;
		string name, selectedVendor;
		while (p--) {
			getline(cin, name);
			double price;
			int cnt;
			scanf("%lf %d\n", &price, &cnt);
			string s;
			for (int i = 0; i < cnt; i++) getline(cin, s);
			if (cnt > maxcnt) {
				maxcnt = cnt;
				lowest_price = price;
				selectedVendor = name;
			}
			else if (cnt == maxcnt) {
				if (price < lowest_price) {
					selectedVendor = name;
					lowest_price = price;
				}
			}

		}
		if (endline) cout << endl;
		cout << "RFP #" << i++ << endl;
		cout << selectedVendor << endl;
		endline = true;
	}
}

