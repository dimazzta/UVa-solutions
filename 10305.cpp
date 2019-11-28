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
vi adj[nax];
vi tsort;
bool visited[nax];

void toposort(int v){
	visited[v] = true;
	
	for (int i = 0; i < adj[v].size(); i++){
		if (!visited[adj[v][i]]) toposort(adj[v][i]);
	}
	tsort.push_back(v);
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m; 
	while(cin >> n >> m, n || m){
		for (int i = 0; i < nax; i++){
			adj[i].clear();
			visited[i] = false;
			tsort.clear();
		}
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= n; i++){
			if (!visited[i]) toposort(i);
		}
		for (int i = tsort.size() - 1; i >= 0; i--){
			if (i < tsort.size() - 1) cout << " ";
			cout << tsort[i];
		}
		cout << endl;
	}
	
	
	

	return 0;
}


