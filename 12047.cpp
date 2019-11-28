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

vector<int> dijkstra(vector<vector<ii>> & adj, int s){
	int n = adj.size();
	vector<int> dist(n, inf);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		ii p = pq.top(); pq.pop();
		int v = p.second;
		int cost = p.first;
		if (dist[v] < cost) continue;
		for(int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].first;
			if (cost + adj[v][i].second < dist[u]){
				dist[u] = cost + adj[v][i].second;
				pq.push({dist[u], u});
			}
		}
	}
	return dist;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int n, m, s, e, p; cin >> n >> m >> s >> e >> p;
		vector<vector<ii>> adj(n + 1), rev_adj(n + 1);
		for (int i = 0; i < m; i++){
			int x, y, w; cin >> x >> y >> w;
			adj[x].push_back({y, w});
			rev_adj[y].push_back({x, w});
		}
		vector<int> forward_dist = dijkstra(adj, s);
		vector<int> reverse_dist = dijkstra(rev_adj, e);
		int mx = -1;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < adj[i].size(); j++){
				int v = i, u = adj[i][j].first, cost = adj[i][j].second;
				if (forward_dist[v] + cost + reverse_dist[u] <= p){
					mx = max(mx, cost);
				}
			}
		}
		cout << mx << endl;
		
	}
	return 0;
}


