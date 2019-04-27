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
	vi rank, p, money;
public:
	UF(int n, vi & m) {
		rank.assign(n, 0);
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		money = m;
	}
	int find(int i) {
		return i == p[i] ? i : (p[i] = find(p[i]));
	}
	void merge(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
				money[y] += money[x];
				money[x] = 0;
			}
			else {
				p[y] = x;
				money[x] += money[y];
				money[y] = 0;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	bool calc() {
		return all_of(money.begin(), money.end(), [](int i) {
			return i == 0;
		});
	}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vi money(n);
		for (int i = 0; i < n; ++i) cin >> money[i];
		UF uf(n, money);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			uf.merge(a, b);
		}
		if (uf.calc()) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

}
