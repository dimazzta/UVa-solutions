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


pair<set<int>, int> find_mst(vector<pair<int, ii>> & edges, int n, int excl){ //edges is sorted
	int result = 0;
	set<int> ans;
	UF uf(n + 1);
	int disj_cnt = n;
	for (int i = 0; i < edges.size(); i++){
		if (!uf.same(edges[i].second.first, edges[i].second.second) && i != excl){
			uf.merge(edges[i].second.first, edges[i].second.second);
			result += edges[i].first;
			disj_cnt--;
			ans.insert(i);
		}
	}
	
	return {ans, disj_cnt == 1 ? result : INT_MAX};
}

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<pair<int, ii>> edges(m);
		for (int i = 0; i < m; i++){
			cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
		}
		sort(edges.begin(), edges.end());
		set<int> orig_mst;
		int first_ans;
		tie(orig_mst, first_ans) = find_mst(edges, n, -1);
		int second_ans = INT_MAX;
		for (auto& edge : orig_mst){
			second_ans = min(second_ans, find_mst(edges, n, edge).second);
		}
		cout << first_ans << " " << second_ans << endl;
	}
	return 0;
}


