#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 2505;
int n;
vector<vector<pair<int, bool>>> adj(nax);
vector<int> diameter_path;
vector<bool> visited(nax);
int diameter_value;
int worst_p;


vector<int> get_diameter(const vector<vector<pair<int, bool>>> &adj_list, int start_node) {
	queue<int> q;
	vector<bool> visited(adj_list.size());
	q.push(start_node);
	visited[start_node] = true;

	int far = start_node;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		far = u;

		for (const auto &item : adj_list[u]) {
			if (!item.second)
				continue;

			int v = item.first;
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
			}
		}
	}

	vector<int> parent(adj_list.size());

	q.push(far);
	visited.assign(adj_list.size(), false);
	visited[far] = true;
	parent[far] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		far = u;

		for (const auto &item : adj_list[u]) {
			if (!item.second)
				continue;

			int v = item.first;
			if (!visited[v]) {
				visited[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}

	vector<int> path;
	while (far != -1) {
		path.push_back(far);
		far = parent[far];
	}
	return path;
}


void clear() {
	diameter_path.clear();
	diameter_value = 0;
	worst_p = 0;
	for (int i = 0; i < nax; i++) {
		visited[i] = false;
		adj[i].clear();
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		clear();
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y;
			x--; y--;
			adj[x].push_back({ y, true });
			adj[y].push_back({ x, true });
		}
		
		// cout << diameter_value << endl;
		//		 for (int i = 0; i < diameter_path.size(); i++){
		//		 	cout << diameter_path[i] << " ";
		//		 }
		//		 cout << endl;


		ii cut;
		ii add;
		int ans = 1e7;
		vi path = get_diameter(adj, 0);
		for (int i = 1; i < path.size(); i++) {
			int u = path[i - 1];
			int v = path[i];

			for (int j = 0; j < adj[u].size(); j++) {
				if (adj[u][j].first == v) {
					adj[u][j].second = false;
				}
			}
			for (int j = 0; j < adj[v].size(); j++) {
				if (adj[v][j].first == u) {
					adj[v][j].second = false;
				}
			}
			
			vi first_tree = get_diameter(adj, u);
			vi second_tree = get_diameter(adj, v);
			int first_len = first_tree.size() - 1;
			int second_len = second_tree.size() - 1;

			int possible = max((int)ceil((first_len) / 2.0) + (int)ceil((second_len) / 2.0) + 1, max(first_len, second_len));
			if (possible < ans) {
				cut.first = u;
				cut.second = v;
				add.first = first_tree[first_tree.size() / 2];
				add.second = second_tree[second_tree.size() / 2];
				ans = possible;
			}


			for (int j = 0; j < adj[u].size(); j++) {
				if (adj[u][j].first == v) {
					adj[u][j].second = true;
				}
			}
			for (int j = 0; j < adj[v].size(); j++) {
				if (adj[v][j].first == u) {
					adj[v][j].second = true;
				}
			}

		}
		cout << ans << endl;
		cout << cut.first + 1 << " " << cut.second + 1 << endl;
		cout << add.first + 1 << " " << add.second + 1 << endl;

	}
	return 0;
}


