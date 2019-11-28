#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 5005;

vector<vi> adj(nax);
vector<bool> vis(nax);
int diam;
int vertex_diam;
set<int> worst;
set<int> best;

void dfs_diameter(int u, vi path, int len) {
	if (len > diam) {
		diam = len;
		vertex_diam = u;
	}
	path.push_back(u);
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			dfs_diameter(v, path, len + 1);
		}
	}
}

void dfs_worst(int u, vi path, int len) {
	path.push_back(u);
	if (len > diam) {
		diam = len;
		worst.clear();
		best.clear();
		worst.insert(u);
		if (path.size() % 2 != 0) {
			best.insert(path[path.size() / 2]);
		}
		else {
			best.insert(path[path.size() / 2]);
			best.insert(path[path.size() / 2 - 1]);
		}
	}
	else if (len == diam) {
		worst.insert(u);
		if (path.size() % 2 != 0) {
			best.insert(path[path.size() / 2]);
		}
		else {
			best.insert(path[path.size() / 2]);
			best.insert(path[path.size() / 2 - 1]);
		}
	}

	
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			dfs_worst(v, path, len + 1);
		}
	}
}

int main() {
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		diam = 0;
		vertex_diam = 0;
		best.clear();
		worst.clear();
		for (int i = 0; i < nax; i++) {
			adj[i].clear();
			vis[i] = false;
		}
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			for (int j = 0; j < k; j++)
			{
				int x; cin >> x;
				adj[i].push_back(x - 1);
			}
		}
		vi p;
		dfs_diameter(0, p, 0);
		p.clear();
		vis.assign(nax, false);
		dfs_worst(vertex_diam, p, 0);
		p.clear();
		vis.assign(nax, false);
		dfs_worst(*worst.begin(), p, 0);
		cout << "Best Roots  :";
		for (auto &s : best) {
			cout << " " << s + 1;
		}
		cout << endl;
		cout << "Worst Roots :";
		for (auto &s : worst) {
			cout << " " << s + 1;
		}
		cout << endl;
	}
	return 0;
}


