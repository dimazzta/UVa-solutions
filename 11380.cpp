#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e7;
const int nax = 2e3;
const int s = 0;
const int t = nax - 1;

vector<vi> adj(nax);
int res[nax][nax];
int cap[nax];
bitset<nax> vis;
vi p;
int f;

void augment(int v, int edge) {
	if (v == s) {
		f = edge;
		return;
	}
	if (p[v] != -1) {
		augment(p[v], min(edge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int max_flow() {
	int mf = 0;
	while (true) {
		f = 0;
		queue<int> q;
		p.assign(nax, -1);
		vis.reset();
		vis[s] = 1;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int j = 0; j < adj[u].size(); j++) {
				int v = adj[u][j];
				if (res[u][v] && !vis[v]) {
					q.push(v);
					vis[v] = true;
					p[v] = u;
				}
			}
		}
		augment(t, inf);
		if (f == 0) {
			break;
		}
		mf += f;
	}
	return mf;
}

void clear() {
	for (int i = 0; i < nax; i++) {
		cap[i] = 0;
		adj[i].clear();
		for (int j = 0; j < nax; j++) {
			res[i][j] = 0;
		}
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, p;
	while (cin >> n >> m >> p) {
		clear();
		vector<vector<char>> a(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		int v_counter = 1;
		map<ii, int> conv;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int u = 0; u < n; u++) {
					for (int v = 0; v < m; v++) {
						if (abs(i - u) + abs(j - v) == 1 && a[i][j] != '~' && a[u][v] != '~') {
							if (!conv.count({ i, j })) {
								conv[{i, j}] = v_counter++;
								if (a[i][j] == '.' || a[i][j] == '*') {
									cap[conv[{i, j}]] = 1;
									if (a[i][j] == '*') {
										res[s][conv[{i, j}]] = 1;
										adj[s].push_back(conv[{i, j}]);
										adj[conv[{i, j}]].push_back(s);
									}
								}
								else {
									cap[conv[{i, j}]] = inf;
									if (a[i][j] == '#') {
										res[conv[{i, j}]][t] = p;
										adj[conv[{i, j}]].push_back(t);
										adj[t].push_back(conv[{i, j}]);
									}
								}
							}
							if (!conv.count({ u, v })) {
								conv[{u, v}] = v_counter++;
								if (a[u][v] == '.' || a[u][v] == '*') {
									cap[conv[{u, v}]] = 1;
									if (a[u][v] == '*') {
										res[s][conv[{u, v}]] = 1;
										adj[s].push_back(conv[{u, v}]);
										adj[conv[{u, v}]].push_back(s);
									}
								}
								else {
									cap[conv[{u, v}]] = inf;
									if (a[u][v] == '#') {
										res[conv[{u, v}]][t] = p;
										adj[conv[{u, v}]].push_back(t);
										adj[t].push_back(conv[{u, v}]);
									}
								}
							}

							res[conv[{i, j}]][conv[{u, v}]] = inf;
							res[conv[{u, v}]][conv[{i, j}]] = inf;
							adj[conv[{i, j}]].push_back(conv[{u, v}]);
							adj[conv[{u, v}]].push_back(conv[{i, j}]);
						}
					}
				}
			}
		}

		for (int i = 0; i < nax; i++) {
			if (cap[i] > 0) {
				int new_vertex = v_counter++;
				for (auto it = adj[i].begin(); it != adj[i].end(); it++){
					int v = *it;
					if (res[i][v] > 0) {
						res[new_vertex][v] = res[i][v];
						adj[new_vertex].push_back(v);
						adj[v].push_back(new_vertex);
						res[i][v] = 0;
					}

				}

				res[i][new_vertex] = cap[i];
				adj[i].push_back(new_vertex);
				adj[new_vertex].push_back(i);
			}
		}

		int ans = max_flow();
		cout << ans << endl;

	}
	return 0;
}


