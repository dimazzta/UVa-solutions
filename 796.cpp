#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

vector<vector<int>> adj;
vi dfs_num;
vi dfs_low;
vi parent;
set<pair<int, int>> bridges;
int dfs_cnt;

void dfs(int v){
	dfs_num[v] = dfs_low[v] = dfs_cnt++;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (dfs_num[u] == 0){
			parent[u] = v;
			dfs(u);
			if (dfs_low[u] > dfs_num[v]){
				bridges.insert({min(v, u), max(v, u)});
			}
			dfs_low[v] = min(dfs_low[v], dfs_low[u]);
		}
		else if (parent[v] != u){
			dfs_low[v] = min(dfs_low[v], dfs_num[u]);
		}
		
	}
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while(scanf("%d", &n) != EOF){
		adj.clear();
		adj.resize(n);
		dfs_num.assign(n, 0);
		dfs_low.assign(n, 0);
		parent.assign(n, 0);
		bridges.clear();
		dfs_cnt = 1;
		
		for (int i = 0; i < n; i++){
			int x; scanf("%d", &x);
			int cnt; scanf(" (%d)", &cnt);
			for (int i = 0; i < cnt; i++){
				int y;
				scanf(" %d", &y);
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}
		for (int i = 0; i < n; i++){
			if (!dfs_num[i]) dfs(i);
		}
		cout << bridges.size() << " critical links" << endl;
		for (auto &s : bridges){
			cout << s.first << " - " << s.second << endl;
		}
		cout << endl;
	}
	return 0;
}


