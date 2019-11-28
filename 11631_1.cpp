#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m, n || m) {
		priority_queue<ii> pq;
		vector<vector<ii>> adj(n);
		vector<bool> taken(n);
		int total_cost = 0;
		for (int i = 0; i < m; i++) {
			int x, y, z; cin >> x >> y >> z;
			adj[x].push_back({ z, y });
			adj[y].push_back({ z, x });
			total_cost += z;
		}
		
		for (int i = 0; i < adj[0].size(); i++) {
			pq.push({ -adj[0][i].first, -adj[0][i].second });
		}
		taken[0] = true;
		int mst_cost = 0;
		while (!pq.empty()) {
			ii v = pq.top(); pq.pop();
			int w = -v.first, u = -v.second;
			if (!taken[u]) {
				mst_cost += w;
				taken[u] = true;
				for (int i = 0; i < adj[u].size(); i++) {
					if (!taken[adj[u][i].second]) pq.push({ -adj[u][i].first, -adj[u][i].second });
				}
			}
		}
		cout << total_cost - mst_cost << endl;
		
	}

	return 0;
}


