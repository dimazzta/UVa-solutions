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
int cntr;
stack<int> st;
vector<bool> stacked;
int n, m; 
int cc_cnt;

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
			low[sv] = low[v];
			if (v == sv) break;
		}
	}
}

void read(){
	cin >> n >> m;
	adj.clear();
	adj.resize(n);
	st = stack<int>();
	stacked.assign(n, false);
	low.assign(n, 0);
	ids.assign(n, 0);
	cntr = 1;
	cc_cnt = 0;
	
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
	}
}
int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	while(t--){
		read();
		for (int i = 0; i < n; i++){
			if (!ids[i]) dfs(i);
		}
		set<int> bad_cc;
		for (int i = 0; i < n; i++){
			int cc = low[i];
			for (int j = 0; j < adj[i].size(); j++){
				int u = adj[i][j];
				int ucc = low[u];
				if (ucc != cc){
					bad_cc.insert(ucc);
				}
			}
		}
		cout << cc_cnt - bad_cc.size() << endl;
	}
	return 0;
}


