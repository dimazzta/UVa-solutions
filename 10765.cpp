#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


vector<vi> adj;
vi dfs_num, dfs_low;
vi pig;
int root;
int rc;
int dfsc;

void dfs(int v, int p){
	dfs_num[v] = dfs_low[v] = dfsc++;
	pig[v] = 1;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (dfs_num[u] == 0){
			if (v == root) rc++;
			dfs(u, v);
			dfs_low[v] = min(dfs_low[v], dfs_low[u]);
			if (dfs_low[u] >= dfs_num[v]){
				pig[v]++;
			}
		}
		else if (u != p){
			dfs_low[v] = min(dfs_low[v], dfs_num[u]);
		}
	}
}

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	while(cin >> n >> m, n || m){
		adj.clear();
		adj.resize(n);
		dfs_num.assign(n, 0);
		dfs_low.assign(n, 0);
		pig.assign(n, 0);
		dfsc = 1;
		root = 0;
		rc = 0;
		
		int x, y;
		while(cin >> x >> y, x != -1 || y != -1){
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for (int i = 0; i < n; i++){
			if (!dfs_num[i]) {
				root = i;
				rc = 0;
				dfs(i, -1);
				pig[i] = rc;
			}
		}
		vector<ii> ans;
		for (int i = 0; i < n; i++){
			ans.push_back({pig[i], i});
		}
		sort(ans.begin(), ans.end(), [](ii a, ii b){
			if (a.first != b.first) return a.first > b.first;
			else return a.second < b.second;
		});
		for (int i = 0; i < m; i++){
			cout << ans[i].second << " " << ans[i].first << endl;
		}
		cout << endl;
	}
	return 0;
}


