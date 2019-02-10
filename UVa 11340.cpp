#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, l;
	char symb;
	double cents, sum;
	

	cin >> n;
	while (n--) {
		cin >> m;	
		vector<double> tbl(65536, 0);
		while (m--) {
			cin >> symb >> cents;
			tbl[symb] = cents / 100;
		}
		cin >> l;
		sum = 0;
		cin.ignore();
		while (l--) {
			string s;
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) {
				sum += tbl[s[i]];
			}
		}
		cout << fixed << setprecision(2) << sum << '$' << endl;
	}
}
