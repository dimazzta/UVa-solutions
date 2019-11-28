#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 105;
vi adj[nax];
vi dfs_num(nax);
vi dfs_low(nax);
vi parent(nax);
vi apoints(nax);
const int dfs_root = 1;
int dfs_counter;
int root_child;

void dfs(int v) {
	dfs_num[v] = dfs_low[v] = dfs_counter++;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i];
		if (dfs_num[u] == 0) {
			if (v == dfs_root) root_child++;
			parent[u] = v;
			dfs(u);
			if (dfs_low[u] >= dfs_num[v]) {
				apoints[v] = 1;
			}
			dfs_low[v] = min(dfs_low[v], dfs_low[u]);
		}
		else if (u != parent[v]) {
			dfs_low[v] = min(dfs_low[v], dfs_num[u]);
		}
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		for (int i = 0; i < nax; i++) {
			adj[i].clear();
			dfs_num[i] = 0;
			dfs_low[i] = 0;
			apoints[i] = 0;
		}
		dfs_counter = 1;
		root_child = 0;
		cin.ignore();

		int x, y;
		while (cin >> x, x) {
			string s;
			getline(cin, s);
			stringstream ss(s);
			while (ss >> y) {
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}
		dfs(1);
		int a_cnt = 0;
		for (int i = 2; i <= n; i++) if (apoints[i]) {
			a_cnt++;	
			//cout << i << endl;
		}
		if (root_child > 1) a_cnt++;
		cout << a_cnt << endl;
	}
	return 0;
}


