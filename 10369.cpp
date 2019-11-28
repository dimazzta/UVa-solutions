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
	UF(int n){
		p.assign(n, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find(int i){
		return p[i] == i ? i : (p[i] = find(p[i]));
	}
	void merge(int i, int j){
		p[find(i)] = find(j);
	}
	bool same(int i, int j){
		return find(i) == find(j);
	}
};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int s, n; cin >> s >> n;
		vii vert(n);
		for (int i = 0; i < n; i++){
			cin >> vert[i].first >> vert[i].second;
		}
		vector<pair<double, ii>> e;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j){
					int x1, x2, y1, y2;
					x1 = vert[i].first;
					x2 = vert[j].first;
					y1 = vert[i].second;
					y2 = vert[j].second;
					
					double dist = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
					e.push_back({dist, {i, j}});
				}
			}
		}
		sort(e.begin(), e.end());
		int disj_cnt = n;
		double mst_weight = 0;
		UF uf(n);
		for (int i = 0; i < e.size() && disj_cnt > s; i++){
			if (!uf.same(e[i].second.first, e[i].second.second)){
				uf.merge(e[i].second.first, e[i].second.second);
				disj_cnt--;
				mst_weight = max(mst_weight, e[i].first);
			}
		}
		cout << setprecision(2) << fixed << mst_weight << endl;
	}
	return 0;
}


