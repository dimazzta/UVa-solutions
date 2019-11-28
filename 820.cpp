#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 105;
const int inf = 1e8;
vector<vector<ii>> adj(nax);
int res[nax][nax];
vi p;
bitset<nax> vis;
int f, s, t;

void augment(int v, int edge){
	if (v == s) {
		f = edge;
		return;
	}
	else{
		if (p[v] != -1) {
			augment(p[v], min(edge, res[p[v]][v]));
			res[p[v]][v] -= f;
			res[v][p[v]] += f;
		}
	}
}

int max_flow(){
	int mf = 0;
	while(true){
		f = 0;
		p.assign(nax, -1);
		vis.reset();
		queue<int> q;
		vis[s] = true; q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i].first;
				if (res[u][v] > 0 && !vis[v]){
					q.push(v);
					vis[v] = true;
					p[v] = u;
				}
			}
		}
		augment(t, inf);
		if (f == 0){
			break;
		}
		mf += f;
	}
	return mf;
}

void clear(){
	for (int i = 0; i < nax; i++){
		adj[i].clear();
		for (int j = 0; j < nax; j++){
			res[i][j] = 0;
		}
	}
}

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int tc = 1;
	while(cin >> n, n){
		clear();
		int c;
		cin >> s >> t >> c;
		for (int i = 0; i < c; i++){
			int x, y, w; cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
			res[x][y] += w;
			res[y][x] += w;
		}
		int ans = max_flow();
		cout << "Network " << tc++ << endl;
		cout << "The bandwidth is " << ans << "." << endl << endl;
	}
	return 0;
}


