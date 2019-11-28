#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;cin.ignore();
	while (t--) {
		
		string s;
		getline(cin, s);
		stringstream ss(s);
		vi a;
		int x;
		while (ss >> x) {
			a.push_back(x);
		}
		int n = a.size();
		int mx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j)
					mx = max(mx, gcd(a[i], a[j]));
			}
		}
		cout << mx << endl;
	}
	return 0;
}


