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

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n; 
	int tc = 1;
	while(cin >> n){
		vector<vector<int>> adj(n);
		vector<bool> visited(n);
		vector<int> indegree(n);
		
		vector<string> conv(n);
		map<string, int> back;
		
		for (int i = 0; i < n; i++){
			cin >> conv[i];
			back[conv[i]] = i;
		}
		
		int m; cin >> m;
		for (int i = 0; i < m; i++){
			string s1, s2; cin >> s1 >> s2;
			adj[back[s1]].push_back(back[s2]);
			indegree[back[s2]]++;
		}
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++){
			if (indegree[i] == 0) q.push(i);
		}
		vector<string> tsort;
		while(!q.empty()){
			int v = q.top(); q.pop();
			tsort.push_back(conv[v]);
			for (int i = adj[v].size() - 1; i >= 0; i--){
				if (indegree[adj[v][i]] > 0){
					indegree[adj[v][i]]--;
					if (indegree[adj[v][i]] == 0){
						q.push(adj[v][i]);
					}
				}
			}
		}
		cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
		for (int i = 0; i < tsort.size(); i++){
			cout << " " << tsort[i];
		}
		cout << ".";
		cout << endl << endl;
		
	}
	
	return 0;
}


