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
	UF(int n) { rank.assign(n, 0); p.resize(n); iota(p.begin(), p.end(), 0); size = n; }
	int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
	int merge(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x != y) {
			if (x == 0) {
				p[y] = x;
				return x;
			}
			else {
				p[x] = y;
				return y;
			}
		}
		return x;
	}
	int c_susp() {
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			if (findSet(i) == 0) cnt++;
		}
		return cnt;
	}
};

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		UF uf(n);
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;

			int merge_result = -1;
			for (int j = 0; j < k; j++) {
				int st;
				cin >> st;
				if (merge_result == -1) {
					merge_result = st;
				}
				else {
					merge_result = uf.merge(merge_result, st);
				}
			}
		}
		cout << uf.c_susp() << endl;
	}

}
