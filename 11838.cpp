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
vi low;
vi ids;
int cc_cnt;
int cntr;
stack<int> st;
vector<bool> stacked;

void dfs(int v){
	low[v] = ids[v] = cntr++;
	st.push(v);
	stacked[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (!ids[u]) dfs(u);
		if (stacked[u]) low[v] = min(low[v], low[u]);
	}
	if (low[v] == ids[v]){
		cc_cnt++;
		while(true){
			int sv = st.top(); st.pop();
			stacked[sv] = false;
			if (sv == v) break;
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
		adj.resize(n + 1);
		low.assign(n + 1, 0);
		ids.assign(n + 1, 0);
		cntr = 1;
		cc_cnt = 0;
		st = stack<int>();
		stacked.assign(n + 1, 0);
		
		int x, y, p;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> p;
			adj[x].push_back(y);
			if (p == 2) adj[y].push_back(x);
		}
		for (int i = 1; i <= n; i++){
			if (!ids[i]) dfs(i);
		}
		if (cc_cnt == 1) cout << 1;
		else cout << 0;
		cout << endl;
	}
	
	return 0;
}


