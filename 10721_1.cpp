#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

ll dp[55][55][55];
int n, m, k;


ll solve(int len, int cnt, int lim) {
	if (len == n && cnt == k && lim <= m) return 1;
	if (len > n || cnt > k || lim > m) return 0;
	if (dp[len][cnt][lim] != -1) return dp[len][cnt][lim];
	return dp[len][cnt][lim] = solve(len + 1, cnt, lim + 1) + solve(len + 1, cnt + 1, 1);
}


void init() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			for (int f = 0; f < 55; f++) {
				dp[i][j][f] = -1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef DEBUG
	freopen("out.txt", "w", stdout);
#endif

	while (cin >> n >> k >> m) {
		init();
		ll ans = solve(1, 1, 1);
		cout << ans << endl;
	}


	return 0;
}

