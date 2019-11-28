#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

map<string, bool> dp;

bool solve(string s) {
	if (s.size() == 0) return 1;
	if (dp.count(s)) {
		return dp[s];
	}
	bool solved = false;
	char last = s[0];
	int cnt = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cnt++;
		}
		else {
			if (cnt > 1) {
				string sbs = s.substr(0, i - cnt);
				sbs += s.substr(i);
				solved |= solve(sbs);
				if (solved) {
					return dp[s] = solved;
				}
			}
			cnt = 1;
		}
	}
	if (cnt > 1) {
		string sbs = s.substr(0, s.size() - cnt);
		solved |= solve(sbs);
	}
	return dp[s] = solved;
}


void init() {
	dp.clear();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef DEBUG
	freopen("out.txt", "w", stdout);
#endif


	int t; cin >> t;
	while (t--) {
		init();
		string s; cin >> s;
		bool c = solve(s);
		if (c) cout << 1 << endl;
		else cout << 0 << endl;
	}


	return 0;
}

