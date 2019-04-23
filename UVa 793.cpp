#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;


class UnionFind {
public:
	vector<int> p, rank;
	UnionFind(int n) {
		rank.resize(n + 1);
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);
	}
	int findSet(int i) {
		return i == p[i] ? i : (p[i] = findSet(p[i]));
	}
	void merge(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
			}
			else {
				p[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
		
	}

	bool sameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
};

int main() {
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		UnionFind uf(n);
		char c;
		int i, j, r = 0, w = 0;
		string s;
		cin.ignore();
		while (getline(cin, s), !s.empty()) {
			sscanf(s.c_str(), "%c %d %d", &c, &i, &j);
			if (c == 'c') {
				uf.merge(i, j);
			}
			else {
				if (uf.sameSet(i, j)) r++;
				else w++;
			}
		}
		cout << r << "," << w << endl;
		if (t != 0) cout << endl;
	}

}
