#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 1005;
vector<vi> adj(nax);
vector<bool> vis(nax);
vector<int> match(nax);

int aug(int l) {
	if (vis[l]) return 0;
	vis[l] = true;
	for (int i = 0; i < adj[l].size(); i++) {
		int r = adj[l][i];
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l; return 1;
		}
	}
	return 0;
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < nax; i++){
			adj[i].clear();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x; cin >> x;
				if (x) {
					adj[i].push_back(n + j);
				}
			}
		}
		match.assign(nax, -1);
		int res = 0;
		for (int i = 0; i < n; i++) {
			vis.assign(nax, false);
			res += aug(i);
		}
		cout << "Case " << tc << ": a maximum of " << res << " nuts and bolts can be fitted together" << endl;
	}
	return 0;
}


