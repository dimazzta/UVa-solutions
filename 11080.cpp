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
vi color(nax);
int cnt_ones = 0;
int cnt_twos = 0;
bool dfs(int v, int c){
	color[v] = c;
	if (c == 1) cnt_ones++;
	else cnt_twos++;
	int ncolor = c == 1 ? 2 : 1;
	bool bp = true;
	for (int i = 0; i < adj[v].size(); i++){
		if (!color[adj[v][i]]){
			bp &= dfs(adj[v][i], ncolor);
		}
		else if (color[adj[v][i]] != ncolor){
			bp = false;
			break;
		}
	}
	return bp;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		for (int i = 0; i < nax; i++){
			adj[i].clear();
			color[i] = 0;
		}
		cnt_ones = 0;
		cnt_twos = 0;
		
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		bool ans = true;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (!color[i]) {
				ans &= dfs(i, 1);
				if (cnt_twos == 0) cnt += cnt_ones;
				else cnt += min(cnt_ones, cnt_twos);
				cnt_ones = 0;
				cnt_twos = 0;
			}
		}
		if (!ans){
			cout << -1 << endl;
		}
		else{
			cout << cnt << endl;
		}
	}
	return 0;
}


