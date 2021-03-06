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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n, m, s, e; cin >> n >> m >> s >> e;
		vector<vii> adj(n);
		for (int i = 0; i < m; i++){
			int x, y, w; cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}
		vector<int> dist(n, inf);
		dist[s] = 0;
		set<ii> q;
		q.insert({0, s});
		while(!q.empty()){
			ii p = *q.begin();
			q.erase(q.begin());
			int v = p.second;
			int cost = p.first;
			for(int i = 0; i < adj[v].size(); i++){
				int u = adj[v][i].first;
				if (cost + adj[v][i].second < dist[u]){
					q.erase({dist[u], u});
					dist[u] = cost + adj[v][i].second;
					q.insert({dist[u], u});
				}
			}
		}
		if (dist[e] == inf){
			cout << "Case #" << tc << ": " << "unreachable" << endl;
		}
		else{
			cout << "Case #" << tc << ": " << dist[e] << endl;
		}
	}
	return 0;
}


