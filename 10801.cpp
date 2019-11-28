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

struct vertex {
	int cost;
	int floor;
	int elevator;
};
struct compareVertex {
	bool operator()(vertex v1, vertex v2) {
		return v1.cost > v2.cost;
	}
};

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	while (cin >> n >> k) {
		vi time(n);
		for (int i = 0; i < n; i++) cin >> time[i];
		vector<vector<vertex>> adj(100);
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			stringstream ss(s);
			int x;
			vi floors;
			while (ss >> x) {
				floors.push_back(x);
			}
			for (int j = 0; j < floors.size(); j++) {
				for (int k = 0; k < floors.size(); k++) {
					if (j != k) {
						vertex v;
						v.floor = floors[k];
						v.cost = time[i] * (abs(floors[k] - floors[j]));
						v.elevator = i;
						adj[floors[j]].push_back(v);
					}
				}
			}
		}
		vector<int> dist(100, inf);
		dist[0] = 0;
		priority_queue<vertex, vector<vertex>, compareVertex> pq;
		for (int i = 0; i < 5; i++) {
			vertex fp = { 0, 0, i };
			pq.push(fp);
		}
		
		while (!pq.empty()) {
			vertex top = pq.top(); pq.pop();
			int floor = top.floor, cost = top.cost, el = top.elevator;
			if (dist[floor] < cost) continue;
			for (int i = 0; i < adj[floor].size(); i++) {
				int u = adj[floor][i].floor;
				int transfer_cost = 0;
				if (adj[floor][i].elevator != el) transfer_cost += 60;
				if (dist[u] > transfer_cost + adj[floor][i].cost + dist[floor]) {
					dist[u] = transfer_cost + adj[floor][i].cost + dist[floor];
					pq.push({ dist[u], u, adj[floor][i].elevator });
				}
			}
		}
		if (dist[k] == inf) {
			cout << "IMPOSSIBLE" << endl;
		}
		else cout << dist[k] << endl;
	}
	return 0;
}


