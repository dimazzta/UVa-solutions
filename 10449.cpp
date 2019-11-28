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
	
	int n;
	int tc = 1;
	while(cin >> n){
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int m; cin >> m;
		vector<vector<ii>> adj(n + 1);
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back({y, pow(a[y] - a[x], 3)});
		}
		vector<int> dist(n + 1, inf);
		if(n){
			dist[1] = 0;
			for (int i = 0; i < n - 1; i++){
				for (int j = 1; j <= n; j++){
					for (int k = 0; k < adj[j].size(); k++){
						int u = adj[j][k].first;
						int cost = adj[j][k].second;
						dist[u] = min(dist[u], cost + dist[j]);
					}
				}
			}
			
			for (int i = 0; i < n - 1; i++){
				for (int j = 1; j <= n; j++){
					for (int k = 0; k < adj[j].size(); k++){
						int u = adj[j][k].first;
						int cost = adj[j][k].second;
						if (cost + dist[j] < dist[u]){
							dist[u] = -inf;
						}
					}
				}
			}
		}
		
		int q; cin >> q;
		cout << "Set #" << tc++ << endl;
		while(q--){
			int x; cin >> x;
			if (dist[x] < 3 || dist[x] == inf) 
			{
				cout << "?" << endl;
			}
			else{
				cout << dist[x] << endl;
			}
		}
	}
	return 0;
}


