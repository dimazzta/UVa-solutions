#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 38;
const int inf = 1e8;
bitset<nax> vis;
vi p;
int res[nax][nax];
int f;

void aug(int v, int min_edge) {
	if (v == 0) {
		f = min_edge;
		return;
	}
	if (p[v] != -1) {
		aug(p[v], min(min_edge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void clear() {
	for (int i = 0; i < nax; i++) {
		for (int j = 0; j < nax; j++) {
			res[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	while (getline(cin, s)) {
		clear();
		int a_cnt = 0;
		do {
			char app = s[0];
			int k = s[1] - '0';
			a_cnt += k;
			res[0][app - 'A' + 1] = k;
			for (int i = 3; i < s.size() - 1; i++) {
				int num = s[i] - '0';
				res[app - 'A' + 1][num + 27] = inf;
			}
			getline(cin, s);
		} while (!s.empty());
		for (int i = 27; i < 37; i++) {
			res[i][37] = 1;
		}

		int mf = 0;
		while (true) {
			f = 0;
			p.assign(nax, -1);
			vis.reset();
			vis.set(0);
			queue<int> q;
			q.push(0);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == 37) break;
				for (int v = 0; v < nax; v++) {
					if (res[u][v] > 0 && !vis[v]) {
						q.push(v);
						vis[v] = true;
						p[v] = u;
					}
				}
			}
			aug(37, inf);
			if (f == 0) {
				break;
			}
			mf += f;
		}
		if (mf == a_cnt) {
			for (int i = 27; i < 37; i++) {
				bool f = false;
				for (int j = 1; j < 27; j++) {
					if (res[i][j] == 1) {
						cout << (char)(j + 'A' - 1);
						f = true;
					}
				}
				if (!f) cout << "_";
			}
			cout << endl;
		}
		else {
			cout << "!" << endl;
		}
	}
	return 0;
}


