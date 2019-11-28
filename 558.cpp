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
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<ii>> adj(n);
		for (int i = 0; i < m; i++){
			int x, y, w; cin >> x >> y >> w;
			adj[x].push_back({y, w});
		}
		vector<int> dist(n, inf);
		dist[0] = 0;
		for (int i = 0; i < n - 1; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < adj[j].size(); k++){
					int u = adj[j][k].first;
					int cost = adj[j][k].second;
					dist[u] = min(dist[u], dist[j] + cost);
				}
			}
		}
		bool neg_cycle = false;
		for (int i = 0; i < n - 1; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < adj[j].size(); k++){
					int u = adj[j][k].first;
					int cost = adj[j][k].second;
					if (dist[j] + cost < dist[u]){
						neg_cycle = true;
						break;
					}
				}
			}
		}
		if (neg_cycle){
			cout << "possible" << endl;
		}
		else{
			cout << "not possible" << endl;
		}
	}
	return 0;
}


