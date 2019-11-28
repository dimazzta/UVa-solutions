#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

struct UF {
	vi p;
	UF(int size) {
		p.assign(size, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find(int i) {
		return p[i] == i ? i : (p[i] = find(p[i]));
	}
	void merge(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			p[x] = y;
		}
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
};

vector<bool> visited;
int mx;

bool dfs(int v, vector<vii> & adj, int u) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int a = adj[v][i].first;
		if (a == u) {
			mx = max(mx, adj[v][i].second);
			return true;
		}
		if (!visited[a]) {
			bool k = dfs(a, adj, u);
			if (k) {
				mx = max(mx, adj[v][i].second);
				return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc = 1;
	int c, s, q;
	while (cin >> c >> s >> q, c || s || q) {
		if (tc > 1) cout << endl;
		vector<pair<int, ii>> e(s);
		for (int i = 0; i < s; i++) {
			cin >> e[i].second.first >> e[i].second.second >> e[i].first;
		}
		sort(e.begin(), e.end());
		vector<vii> adj(c + 1);
		UF uf(c + 1);
		for (int i = 0; i < s; i++) {
			if (!uf.same(e[i].second.first, e[i].second.second)) {
				uf.merge(e[i].second.first, e[i].second.second);
				adj[e[i].second.first].push_back({ e[i].second.second, e[i].first });
				adj[e[i].second.second].push_back({ e[i].second.first, e[i].first });
			}
		}
		cout << "Case #" << tc++ << endl;

		for (int i = 0; i < q; i++) {
			visited.assign(c + 1, false);
			mx = -1;
			int x, y; cin >> x >> y;
			dfs(x, adj, y);
			if (mx == -1) cout << "no path" << endl;
			else cout << mx << endl;

		}
		
	}
	return 0;
}


