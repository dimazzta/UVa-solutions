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

	int l, u, r;
	int tc = 1;
	while(cin >> l >> u >> r, l || u || r){
		vi a(r);
		for (int i = 0; i < r; i++) cin >> a[i];
		vector<vector<int>> adj(10000);
		for (int i = 0; i <= 9999; i++){
			for (int j = 0; j < r; j++){
				int next = i + a[j];
				next %= 10000;
				adj[i].push_back(next);
			}
		}
		queue<int> q;
		vector<int> dist(10000, inf);
		q.push(l); dist[l] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			if (x == u) break;
			for (int i = 0; i < adj[x].size(); i++){
				int v = adj[x][i];
				if (dist[v] == inf){
					dist[v] = dist[x] + 1;
					q.push(v);
				}
			}
		}
		if (dist[u] == inf){
			cout << "Case " << tc++ << ": Permanently Locked" << endl;
		}
		else cout << "Case " << tc++ << ": " << dist[u] << endl;
	
	}
	return 0;
}


