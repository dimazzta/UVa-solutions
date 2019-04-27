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
	UF(int n) { rank.assign(n + 1, 0); p.resize(n + 1); iota(p.begin(), p.end(), 0); size.assign(n + 1, 1); }
	int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }
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
	bool same(int i, int j) {
		return find(i) == find(j);
	}
	int max_group() {
		return *max_element(size.begin(), size.end());
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		UF uf(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			uf.merge(a, b);
		}
		cout << uf.max_group() << endl;
	}

}
