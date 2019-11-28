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

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n != -1) {
		vector<vector<ii>> adj(n + 1);
		vector<int> values(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> values[i];
			int x; cin >> x;
			for (int j = 0; j < x; j++) {
				int y; cin >> y;
				adj[i].push_back({ y, 0 });
			}

		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				adj[i][j].second = -values[adj[i][j].first];
			}
		}
		vector<int> dist(n + 1, inf);
		dist[1] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < adj[j].size(); k++) {
					int u = adj[j][k].first;
					int cost = adj[j][k].second;
					if (dist[j] + cost < dist[u] && dist[j] + cost < 100){
						dist[u] = dist[j] + cost;
					}
				}
			}
		}

		
		if (dist[n] < 100) {
			cout << "winnable" << endl;
		}
		else {
			bool cycle = false;
		
			set<int> v;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 1; j <= n; j++) {
					for (int k = 0; k < adj[j].size(); k++) {
						int u = adj[j][k].first;
						int cost = adj[j][k].second;
						if (dist[j] + cost < dist[u] && dist[j] + cost < 100){
							cycle = true;
							v.insert(u);
						}
					}
				}
			}
			if (cycle){
				queue<int> q;
				for (auto &s : v){
					q.push(s);
				}
				bool can_reach = false;
				vector<bool> vis(n + 1);
				while(!q.empty()){
					int p = q.front(); q.pop();
					vis[p] = true;
					if (p == n){
						can_reach = true;
						break;
					}
					for (int i = 0; i < adj[p].size(); i++){
						if (!vis[adj[p][i].first]) q.push(adj[p][i].first);
					}
				}
				if (can_reach){
					cout << "winnable" << endl;
				}
				else{
					cout << "hopeless" << endl;
				}
			}
			else{
				cout << "hopeless" << endl;
			}
	
		}
	}
	return 0;
}


