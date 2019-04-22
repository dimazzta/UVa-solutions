#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

int main() {
	int t;

	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;
		mi mat(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}

		bool f = true;
		set<pair<int, int>> s;

		for (int i = 0; i < m; i++) {
			int cnt = 0, pr = 0;
			for (int j = 0; j < n; j++) {
				if (mat[j][i]) {
					cnt++;
					if (cnt == 1) pr = j;
					else if (cnt == 2) {
						if (s.count({ pr, j }) == 0) {
							s.insert({ pr, j });
						}
						else {
							f = false;
							break;
						}
					}
					else {
						f = false;
						break;
					}
				}
			}
			if (cnt != 2) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
