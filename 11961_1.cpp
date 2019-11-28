#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int n, k;
set<string> ans;
char m[] = { 'A', 'G', 'T', 'C' };
string orig;



void solve(string s, int mask, int size) {
	if (size == k) {
		ans.insert(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0) {
			for (int j = 0; j < 4; j++) {
				char tmp = s[i];
				s[i] = m[j];
				solve(s, mask | (1 << i), size + 1);
				s[i] = tmp;
			}
		}
	}


}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ans.clear();
		cin >> n >> k;
		string s;
		cin >> s;
		solve(s, 0, 0);
		cout << ans.size() << endl;
		for (auto &p : ans) {
			cout << p << endl;
		}
	}
	return 0;
}


