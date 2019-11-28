#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

vector<bool> visited;
vector<vi> adj;

void dfs(int u){
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (!visited[v]) dfs(v);
	}
}


int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	while(cin >> n >> m){
		vector<int> deg(n);
		visited.assign(n, false);
		adj.clear();
		adj.resize(n);
		int st = 0;
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			deg[x]++;
			deg[y]++;
			st = x;
		}
		dfs(st);
		bool can = true;
		for (int i = 0; i < n; i++) {
			can &= (deg[i] % 2 == 0);
			if (deg[i])
				can &= visited[i];
		}
		
		if (can && m){
			cout << "Possible" << endl;
		}
		else{
			cout << "Not Possible" << endl;
		}
		
	}
	return 0;
}


