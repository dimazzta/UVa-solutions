#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e8;

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc = 1;
	int n;
	while (cin >> n, n) {
		map<string, int> conv;
		vector<string> back(1000);
		vector<vi> mat(1000, vi(1000, inf));
		for (int i = 0; i < 1000; i++) mat[i][i] = 0;
		int idx = 0;
		for (int i = 0; i < n; i++) {
			int cnt; cin >> cnt;
			string p_str;
			for (int j = 0; j < cnt; j++) {
				string s1; cin >> s1;
				if (!conv.count(s1)) {
					conv[s1] = idx;
					back[idx] = s1;
					idx++;
				}
				if (!p_str.empty()) mat[conv[p_str]][conv[s1]] = 1;
				p_str = s1;
			}
		}
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			string s1, s2; cin >> s1 >> s2;
			mat[conv[s1]][conv[s2]] = 1;
		}
		for (int k = 0; k < idx; k++) {
			for (int i = 0; i < idx; i++) {
				for (int j = 0; j < idx; j++) {
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		set<ii> prs;
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < idx; j++) {
				if (i != j) {
					if (mat[i][j] == inf && mat[j][i] == inf) {
						prs.insert({ min(i, j), max(i, j) });
					}
				}
			}
		}
		if (prs.size() == 0) {
			cout << "Case " << tc++ << ", " << "no concurrent events." << endl;
		}
		else {
			cout << "Case " << tc++ << ", " << prs.size() << " concurrent events:" << endl;
			int cnt = 0;
			for (auto &p : prs) {
				cout << "(" << back[p.first] << "," << back[p.second] << ") ";
				cnt++;
				if (cnt == 2) break;
			}
			cout << endl;
		}
	}
	return 0;
}


