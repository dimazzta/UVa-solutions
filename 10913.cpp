#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 100;
int n, k;
int a[nax][nax];
int dp[nax][nax][6][3];

int dr[] = { 0, 1, 0 };
int dc[] = { -1, 0, 1 };
const int inf = 1e7;
// 0 top
// 1 left
// 2 right

int solve(int r, int c, int neg, int dir) {
	if (a[r][c] < 0) neg++;
	if (neg > k) return -inf;
	if (r == n - 1 && c == n - 1) {
		return a[r][c];
	}

	if (dp[r][c][neg][dir] != -inf) return dp[r][c][neg][dir];

	int ans = -inf;
	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
			if (dir == 1 && nc < c) continue;
			if (dir == 2 && nc > c) continue;
			if (nc > c) {
				ans = max(ans, a[r][c] + solve(nr, nc, neg, 1));
			}
			else if (nc < c) {
				ans = max(ans, a[r][c] + solve(nr, nc, neg, 2));
			}
			else ans = max(ans, a[r][c] + solve(nr, nc, neg, 0));
		}
	}


	return dp[r][c][neg][dir] = ans;
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc = 1;
	while (cin >> n >> k, n || k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				for (int v = 0; v < 6; v++) {
					for (int u = 0; u < 3; u++) {
						dp[i][j][v][u] = -inf;
					}
				}
			}
		}
		int ans = -inf;

		ans = max(ans, solve(0, 0, 0, 1));

		if (ans < -1e6) {
			cout << "Case " << tc++ << ": impossible" << endl;
		}
		else {
			cout << "Case " << tc++ << ": " << ans << endl;
		}

	}
	return 0;
}


