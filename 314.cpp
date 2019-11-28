#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

map<string, int> directions;
const int nax = 55;
const int inf = 1e9;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	directions["north"] = 0;
	directions["east"] = 1;
	directions["south"] = 2;
	directions["west"] = 3;

	int n, m;
	while (cin >> n >> m, n || m) {
		vector<vi> bad(n + 1, vi(m + 1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x; cin >> x;
				if (x) {
					bad[i][j] = bad[i][j + 1] = bad[i + 1][j] = bad[i + 1][j + 1] = 1;
				}
			}
		}

		int r, c, r1, c1;
		cin >> r >> c >> r1 >> c1;
		string s; cin >> s;
		int dir = directions[s];
		vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vi(4, inf)));
		queue<pair<ii, int>> q;
		dist[r][c][dir] = 0;
		q.push({ { r, c }, dir });
		int ans = -1;
		while (!q.empty()) {
			int row, col, dir;
			pair<ii, int> p = q.front(); q.pop();
			row = p.first.first, col = p.first.second, dir = p.second;
			for (int i = 1; i <= 3; i++) {
				int next_row = row, next_col = col;
				if (dir == 0) next_row -= i;
				if (dir == 1) next_col += i;
				if (dir == 2) next_row += i;
				if (dir == 3) next_col -= i;
	
				if (next_row >= 1 && next_row <= n - 1 && next_col >= 1 && next_col <= m - 1 && !bad[next_row][next_col]) {
					if (dist[next_row][next_col][dir] == inf) {
						dist[next_row][next_col][dir] = dist[row][col][dir] + 1;
						q.push({ { next_row, next_col }, dir });
						//cout << "updated " << next_row << ", " << next_col << ", " << dir << ": " << dist[row][col][dir] + 1 << endl;
					}
				}
				else break;
			}
			int left = (dir - 1) % 4;
			int right = (dir + 1) % 4;
			if (left < 0) left += 4;

			if (dist[row][col][left] == inf) {
				dist[row][col][left] = dist[row][col][dir] + 1;
				q.push({ { row, col }, left });
				//cout << "updated " << row << ", " << col << ", " << left << ": " << dist[row][col][dir] + 1 << endl;
			}
			if (dist[row][col][right] == inf) {
				dist[row][col][right] = dist[row][col][dir] + 1;
				q.push({ { row, col }, right });
				//cout << "updated " << row << ", " << col << ", " << right << ": " << dist[row][col][dir] + 1 << endl;
			}
		}
		int mn = inf;
		for (int i = 0; i < 4; i++) {
			mn = min(mn, dist[r1][c1][i]);
		}
		if (mn == inf) {
			cout << -1 << endl;
		}
		else cout << mn << endl;
		//system("pause");
	}

	return 0;
}


