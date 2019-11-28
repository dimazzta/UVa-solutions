#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e9;

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	bool f = false;
	while(t--){
		if (f) cout << endl;
		f = true;
		int n, e, t, m;
		cin >> n >> e >> t >> m;
		vector<vector<ii>> adj(n + 1);
		for (int i = 0; i < m; i++){
			int x, y, w; cin >> x >> y >> w;
			adj[y].push_back({x, w});
		}
		vector<int> dist(n + 1, inf);
		priority_queue<ii> pq;
		dist[e] = 0;
		pq.push({0, e});
		while(!pq.empty()){
			int u, cost;
			ii p = pq.top(); pq.pop();
			cost = -p.first;
			u = p.second;
			if (dist[u] < cost) continue;
			for (int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i].first;
				if (dist[v] > cost + adj[u][i].second){
					dist[v] = adj[u][i].second + cost;
					pq.push({-dist[v], v});
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (dist[i] <= t) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}


