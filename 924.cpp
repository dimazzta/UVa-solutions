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

	int e; cin >> e;
	vector<vector<int>> adj(e);
	for (int i = 0; i < e; i++){
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++){
			int x; cin >> x;
			adj[i].push_back(x);
		}
	}
	int t; cin >> t;
	while(t--){
		vector<ii> dist(e, {inf, inf});
		int source; cin >> source;
		queue<int> q; 
		q.push(source);
		dist[source].first = 0;
		while(!q.empty()){
			int cnt = 0;
			int u = q.front(); q.pop();
			for (int i = 0; i < adj[u].size(); i++){
				if (dist[adj[u][i]].first == inf){
					cnt++;
					dist[adj[u][i]].first = dist[u].first + 1;
					q.push(adj[u][i]);
				}
			}
			dist[u].second = cnt; 
		}
		int mx_boom = -1;
		int mx_day = -1;
		map<int, int> sz;
		for (int i = 0; i < e; i++){
			if (dist[i].second != inf){
				sz[dist[i].first] += dist[i].second;
			}
		}
		for (int i = 0; i < e; i++){
			if (sz[i] > mx_boom){
				mx_boom = sz[i];
				mx_day = i + 1;
			}
		}
		if (mx_boom <= 0){
			cout << 0 << endl;
		} 
		else{
			cout << mx_boom << " " << mx_day << endl;
		}
		
	
	}
	return 0;
}


