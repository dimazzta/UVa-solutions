#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

const int N = 100;

class UF {
private:
	vi rank, p;
	int size;
public:
	UF(int n) {
		rank.assign(N, 0); p.resize(N); iota(p.begin(), p.end(), 0);
		size = n;
	}
	int find(int i) {
		return p[i] == i ? i : (p[i] = find(p[i]));
	}
	void merge(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
			}
			else {
				p[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
			size--;
		}
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
	int getSize() {
		return size;
	}
};

int toInt(char c) {
	return c - 'A';
}

int main() {
	int n, m;

	while (cin >> n) {
		cin >> m;
		UF uf(n);
		string s;
		cin >> s;
		int repr = toInt(s[0]);
		uf.merge(toInt(s[0]), toInt(s[1]));
		uf.merge(toInt(s[0]), toInt(s[2]));
		

		uw_graph graph(N);

		for (int i = 0; i < m; i++) {
			string con;
			cin >> con;
			graph[toInt(con[0])].push_back(toInt(con[1]));
			graph[toInt(con[1])].push_back(toInt(con[0]));
		}

		int ans = 0;
		bool f = true;
		while (uf.getSize() > 1) {
			int cnt = 0;
			vector<int> tba;
			for (int i = 0; i < N; i++) {
				if (graph[i].size()) {
					if (!uf.same(i, repr)) {
						int t = 0;
						for (int j = 0; j < graph[i].size(); j++) {
							if (uf.same(graph[i][j], repr)) t++;
						}
						if (t >= 3) {
							tba.push_back(i);
							cnt++;
						}
					}
				}
			}
			if (cnt == 0) {
				f = false;
				break;
			}
			for (int i = 0; i < cnt; i++) {
				uf.merge(repr, tba[i]);
			}
			ans++;
		}
		if (!f) {
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		}
		else {
			cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
		}
	}
}
