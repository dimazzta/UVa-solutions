#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 305;
vi adj[nax];
vi color(nax);

bool dfs(int v, int c) {
	color[v] = c;
	int ncolor = c == 1 ? 2 : 1;
	bool bp = true;
	for (int i = 0; i < adj[v].size(); i++) {
		if (color[adj[v][i]] == 0) {
			bp &= dfs(adj[v][i], ncolor);
		}
		else {
			if (color[adj[v][i]] != ncolor) {
				bp = false;
				break;
			}
		}
	}
	return bp;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		for (int i = 0; i < nax; i++) {
			adj[i].clear();
			color[i] = 0;
		}
		int x, y;
		while (cin >> x >> y, x || y) {
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		bool ans = true;
		for (int i = 1; i <= n; i++) {
			if (!color[i]) ans &= dfs(i, 1);
		}
		cout << (ans ? "YES" : "NO") << endl;
	}


	return 0;
}


