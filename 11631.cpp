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
	int s;
	UF(int size){
		s = size;
		p.assign(size, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find(int v){
		return v == p[v] ? v : (p[v] = find(p[v]));
	}
	void merge(int i, int j){
		int x = find(i), y = find(j);
		if (x != y){
			p[x] = y;
			s--;
		}
	}
	bool same(int i, int j){
		return find(i) == find(j);
	}
};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	while(cin >> n >> m, n || m){
		vector<pair<int, ii>> edges(m);
		int total_cnt = 0;
		for (int i = 0; i < m; i++){
			cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
			total_cnt += edges[i].first;
		}
		sort(edges.begin(), edges.end());
		UF u(n);
		int mst_cnt = 0;
		for (int i = 0; i < m && u.s > 1; i++){
			if (!u.same(edges[i].second.first, edges[i].second.second)){
				u.merge(edges[i].second.first, edges[i].second.second);
				mst_cnt += edges[i].first;
			}
		}
		cout << total_cnt - mst_cnt << endl;
	}
	
	
	return 0;
}


