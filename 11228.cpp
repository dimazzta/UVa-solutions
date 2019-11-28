#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


struct UF{
	vi p;
	vi h;
	int s;
	UF(int size){
		p.assign(size, 0);
		h.assign(size, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find(int v) {
		return (p[v] == v ? p[v] : (p[v] = find(p[v])));
	}
	void un(int i, int j){
		int x = find(i), y = find(j);
		if (x != y){
			if (h[x] < h[y]){
				p[x] = y;
			}
			else {
				p[y] = x;
				if (h[x] == h[y]) h[x]++;
			}
		}
	}
	bool same(int i, int j){
		int x = find(i), y = find(j);
		return x == y;
	}
};


int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int  t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n, r; cin >> n >> r;
		vector<ii> vertices(n);
		vector<pair<double, ii>> edges;
		for (int i = 0; i < n; i++){
			cin >> vertices[i].first >> vertices[i].second;
		}
		int e_count = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j){
					int x1 = vertices[i].first, x2 = vertices[j].first, y1 = vertices[i].second, y2 = vertices[j].second;
					double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
					edges.push_back({dist, {i, j}});
					e_count++;
				}
			}
		}
		sort(edges.begin(), edges.end());
		UF uf(e_count);
		double road_cost = 0, rail_cost = 0;
		int states = 1;
		for (int i = 0; i < edges.size() && e_count > 1; i++){
			if (!uf.same(edges[i].second.first, edges[i].second.second)){
				e_count--;
				if (edges[i].first > r) {
					rail_cost += edges[i].first;
					states++;
				}
				else road_cost += edges[i].first;
				uf.un(edges[i].second.first, edges[i].second.second);
			}
		}
		cout << "Case #" << tc << ": " << states << " " << round(road_cost) << " " << round(rail_cost) << endl;
	}
	return 0;
}


