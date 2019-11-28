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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; 
	while(cin >> n, n){
		string from, to; cin >> from >> to;
		vector<pair<string, pair<string, string>>> lang(n + 2);
		map<string, int> conv;
		
		for (int i = 0; i < n; i++){
			cin >> lang[i].second.first >> lang[i].second.second >> lang[i].first;
			conv[lang[i].first] = i;
		}
		
		vector<vector<ii>> adj(n + 2);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j){
					if (lang[i].second.first == lang[j].second.first 
					|| lang[i].second.first == lang[j].second.second
					|| lang[i].second.second == lang[j].second.second
					|| lang[i].second.second == lang[j].second.first){
						if (lang[i].first[0] != lang[j].first[0]){
							adj[i].push_back({j, lang[j].first.size()});
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (lang[i].second.first == from || lang[i].second.second == from){
				adj[n].push_back({i, lang[i].first.size()});
			}
			if (lang[i].second.first == to || lang[i].second.second == to){
				adj[i].push_back({n + 1, 0});
			}
		}
		vector<int> dist(n + 2, inf);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		dist[n] = 0;
		pq.push({0, n});
		while(!pq.empty()){
			ii p = pq.top(); pq.pop();
			if (dist[p.second] < p.first) continue;
			for (int i = 0; i < adj[p.second].size(); i++){
				int u = adj[p.second][i].first;
				if (dist[u] > adj[p.second][i].second + dist[p.second]){
					dist[u] = adj[p.second][i].second + dist[p.second];
					pq.push({dist[u], u});
				}
			}
		}
		if (dist[n + 1] == inf){
			cout << "impossivel" << endl;
		}
		else{
			cout << dist[n + 1] << endl;
		}
	}
	return 0;
}


