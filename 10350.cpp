#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e8;

vector<int> ts;
vector<bool> visited;
vector<vii> adj;

void topsort(int v) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i].first;
		if (!visited[u]) {
			topsort(u);
		}
	}
	ts.push_back(v);
}



int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	while (cin >> s) {
		int n, m; cin >> n >> m;

		adj.clear();
		visited.assign(n * m, false);
		ts.clear();
		adj.resize(n * m);
		vi indegree(n * m);

		for (int i = 0; i < m * (n - 1); i++) {
			int k = i / m;
			int v = k * m + i % m;
			for (int j = 0; j < m; j++) {
				int x; cin >> x;
				int u = (k + 1) * m + j;
				adj[v].push_back({ u, x });
				indegree[u]++;
			}
		}
		for (int i = 0; i < n * m; i++) {
			if (!visited[i]) topsort(i);
		}

		reverse(ts.begin(), ts.end());
		vi dp(n * m, inf);
		int m_len = inf;
		for (int i = 0; i < n * m; i++) {
			int u = ts[i];
			if (!indegree[u]) dp[u] = 0;
			bool leaf = true;
			for (int j = 0; j < adj[u].size(); j++) {
				leaf = false;
				int v = adj[u][j].first;
				dp[v] = min(dp[v], dp[u] + adj[u][j].second + 2);
			}
			if (leaf) {
				m_len = min(m_len, dp[u]);
			}
		}
		cout << s << endl;
		cout << m_len << endl;
	}
	return 0;
}


