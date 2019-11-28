#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		string s; int n, m; cin >> s >> n >> m;
		vector<vi> a(n, vi(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		int m_length = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vector<vi> dp(n, vi(m));
				dp[i][j] = 1;
				queue<ii> q;
				q.push({ i, j });
				while (!q.empty()) {
					ii u = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int nr = u.first + dr[i];
						int nc = u.second + dc[i];
						if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] < a[u.first][u.second]) {
							q.push({ nr, nc });
							dp[nr][nc] = max(dp[nr][nc], dp[u.first][u.second] + 1); // ?
							m_length = max(m_length, dp[nr][nc]);
						}
					}
				}
			}
		}
		cout << s << ": " << m_length << endl;

	}
	return 0;
}


