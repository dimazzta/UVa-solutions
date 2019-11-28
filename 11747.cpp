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
	UF(int size){
		p.assign(size, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find(int i){
		return p[i] == i ? i : (p[i] = find(p[i]));
	}
	void merge(int i, int j){
		int x = find(i), y = find(j);
		if (x != y){
			p[x] = y;
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
		vector<pair<int, ii>> e(m);
		for (int i = 0; i < m; i++){
			cin >> e[i].second.first >> e[i].second.second >> e[i].first;
		}
		sort(e.begin(), e.end());
		UF u(n);
		set<int> heaviest;
		for (int i = 0; i < m; i++){
			if (!u.same(e[i].second.first, e[i].second.second)){
				u.merge(e[i].second.first, e[i].second.second);
			}
			else{
				heaviest.insert(e[i].first);
			}
		}
		if(heaviest.empty()){
			cout << "forest" << endl;
		}
		else{
			bool f = false;
			for (auto & s: heaviest){
				if (f) cout << " ";
				else f = true;
				cout << s;
			}
			cout << endl;
		}
	}

	return 0;
}


