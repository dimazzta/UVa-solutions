#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	cin.ignore();
	string s;
	getline(cin, s);

	bool f = false;
	while (t--) {
		if (f) cout << endl;
		f = true;
		getline(cin, s);
		getline(cin, s);
		double total = 0;
		do {
			stringstream ss(s);
			int x1, x2, y1, y2;
			ss >> x1 >> y1 >> x2 >> y2;
			total += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / 1000.0 / 20.0 * 2.0;
			getline(cin, s);
		} while (!s.empty());
		int hours = total;
		int mins = round((total - hours) * 60.0);
		if (mins == 60) {
			hours++;
			mins = 0;
		}
		string m_s = to_string(mins);
		if (m_s.size() == 1) m_s = "0" + m_s;
		cout << hours << ":" << m_s << endl;
	}
	return 0;
}


