#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 205;
vi adj[nax];
int color[nax];

bool dfs(int v, int c){
	color[v] = c;
	bool bp = true;
	for (int i = 0; i < adj[v].size(); i++){
		int ncolor = c == 1 ? 2 : 1;
		if (!color[adj[v][i]]){
			bp &= dfs(adj[v][i], ncolor);
		}
		else{
			if (color[adj[v][i]] != ncolor){
				bp = false;
				break;
			}
		}
	}
	return bp;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	while(cin >> n, n){
		cin >> m;
		for (int i = 0; i < nax; i++){
			adj[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < m; i++){
			int x, y;cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool ans = dfs(0, 1);
		cout << (ans ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
	}
	return 0;
}


