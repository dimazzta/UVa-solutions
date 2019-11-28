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
list<int> cyc;
vector<vector<pair<int, bool>>> adj(nax);

struct uf {
	vi p;
	int size;
	uf(int n) {
		p.assign(n, 0);
		iota(p.begin(), p.end(), 0);
		size = n;
	}
	int find(int i) {
		return (p[i] == i) ? i : (p[i] = find(p[i]));
	}

	void join(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			p[x] = y;
			size--;
		}
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
};

void dfs(list<int>::iterator i, int u) {
	for (int j = 0; j < adj[u].size(); j++) {
		pair<int, bool> &v = adj[u][j];
		if (v.second) {
			v.second = false;
			for (int k = 0; k < adj[v.first].size(); k++) {
				pair<int, bool> &nu = adj[v.first][k];
				if (nu.second && nu.first == u) {
					nu.second = false;
					break;
				}
			}
			dfs(cyc.insert(i, u), v.first);
		}
	}
}


int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		if (tc > 1) cout << endl;
		cyc = list<int>();
		for (int i = 0; i < nax; i++) {
			adj[i].clear();
		}

		int n; cin >> n;
		uf u(55);
		vi deg(55);
		int start = 0;
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			x--; y--;
			start = x;
			adj[x].push_back({ y, true });
			adj[y].push_back({ x, true });
			deg[x]++;
			deg[y]++;
			u.join(x, y);
		}

		bool can = true;
		for (int i = 0; i < 55; i++) {
			can &= (deg[i] % 2 == 0);
			if (deg[i]) {
				can &= u.same(i, start);
			}
		}
		

		cout << "Case #" << tc << endl;
		if (!can) {
			cout << "some beads may be lost" << endl;
		}
		else {
			dfs(cyc.begin(), start);

			for (auto it = cyc.begin(); it != cyc.end();) {
				cout << (*it) + 1 << " ";
				it++;
				if (it == cyc.end()) {
					cout << (*cyc.begin()) + 1;
				}
				else {
					cout << (*it) + 1;
				}
				cout << endl;
			}

		}
	}
	return 0;
}


