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
	void merge(int i, int j) { int x = find(i), y = find(j); if (x != y) { p[x] = y; size--; } }
	int getSize() { return size; }
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		int t, p;
		cin >> p >> t;
		UF uf(p);
		string s;
		cin.ignore();
		vector<set<int>> mat(p + 1);
		while (true) {
			int a, b;
			getline(cin, s);
			if (s.empty()) break;
			sscanf(s.c_str(), "%d %d%", &a, &b);
			mat[a].insert(b);
		}

		for (int i = 1; i <= p; i++) {
			for (int j = i + 1; j <= p; j++) {
				if (mat[i] == mat[j]) {
					uf.merge(i, j);
				}
			}
		}
		cout << uf.getSize() << endl;
		if (n != 0) cout << endl;
	}

}
