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

	int t; cin >> t;
	bool f = false;
	while(t--){
		if (f) cout << endl;
		f = true;
		map<string, int> v;
		vector<string> a;
		string s;
		int idx = 0;
		while(cin >> s, s != "*"){
			a.push_back(s);
			v[s] = idx++;
		}
		int n = a.size();
		vector<vector<int>> adj(n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j){
					if (a[i].size() == a[j].size()){
						int diff = 0;
						for (int k = 0; k < a[i].size(); k++){
							if (a[i][k] != a[j][k]) diff++;
						}
						if (diff == 1){
							adj[i].push_back(j);
							adj[j].push_back(i);
						}
					}
				}
			}
		}
		
		cin.ignore();
		string tmp;
		while(true){
			getline(cin, tmp);
			if (tmp.empty()) break;
			stringstream ss(tmp);
			string s1, s2;
			ss >> s1 >> s2;
			int source = v[s1], dest = v[s2];
			
			vector<int> dist(n, inf);
			dist[source] = 0;
			queue<ii> q;
			q.push({source, 0});
			
			while(!q.empty()){
				ii vertex = q.front(); q.pop();
				for (int i = 0; i < adj[vertex.first].size(); i++){
					int u = adj[vertex.first][i];
					if (dist[u] == inf){
						dist[u] = vertex.second + 1;
						q.push({u, dist[u]});
					}
				}
			}
			
			cout << s1 << " " << s2 << " " << dist[dest] << endl;
		}
	}
	return 0;
}


