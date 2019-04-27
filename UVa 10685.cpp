#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;


class UF {
private:
	vi rank, p, size;
public:
	UF(int n) { rank.assign(n, 0); p.resize(n); iota(p.begin(), p.end(), 0); size.assign(n, 1); }
	int find(int i) { return p[i] == i ? i : (p[i] = find(p[i])); }
	void merge(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
				size[y] += size[x];
			}
			else {
				p[y] = x;
				size[x] += size[y];
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	bool same(int i, int j) { return find(i) == find(j); }
	int large_set() {
		return *max_element(size.begin(), size.end());
	}
};

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		UF uf(n);
		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			mp[s] = i;
		}
		for (int i = 0; i < m; i++) {
			string s, s1;
			cin >> s >> s1;
			uf.merge(mp[s], mp[s1]);
		}
		cout << uf.large_set() << endl;
	}


}
