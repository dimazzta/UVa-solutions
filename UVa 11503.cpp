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
	UF(int n) {
		p.resize(n);
		rank.assign(n, 0);
		size.assign(n, 1);
		iota(p.begin(), p.end(), 0);
	}
	int find(int i) {
		return i == p[i] ? i : (p[i] = find(p[i]));
	}
	int merge(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
				size[y] += size[x];
				return size[y];
			}
			else {
				p[y] = x;
				size[x] += size[y];
				if (rank[x] == rank[y]) rank[x]++;
				return size[x];
			}
		}
		else return size[x];
	}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int f;
		cin >> f;
		UF uf(2 * f);
		map<string, int> mp;
		int k = 0;

		for (int i = 0; i < f; i++) {
			string f1, f2;
			cin >> f1 >> f2;
			if (!mp.count(f1)) mp[f1] = k++;
			if (!mp.count(f2)) mp[f2] = k++;
			cout << uf.merge(mp[f1], mp[f2]) << endl;
		}
	}

}
