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
	vi rank, p;
	int size;
public:
	UF(int n) { rank.assign(n + 1, 0); p.resize(n + 1); iota(p.begin(), p.end(), 0); size = n; }
	int find(int i) { return p[i] == i ? i : (p[i] = find(p[i])); }
	void merge(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
			}
			else {
				p[y] = x;
				if (rank[x] == rank[y]) {
					rank[x]++;
				}
			}
			size--;
		}
	}
	bool same(int i, int j) { return find(i) == find(j); }
	int count() { return size; }
};

int main() {
	int n, m;
	int c = 1;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		UF uf(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			uf.merge(a, b);
		}
		cout << "Case " << c++ << ": " << uf.count() << endl;
	}
}
