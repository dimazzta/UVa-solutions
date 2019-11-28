#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 605;
int n, k;
int a[nax];
int dp[nax][nax];

int solve(int pos, int left) {
	if (pos == n) return 0;
	if (left == 0) {
		int ans = 0;
		for (int i = pos; i < n; i++) {
			ans += a[i];
		}
		return ans;
	}
	if (dp[pos][left] != -1) return dp[pos][left];

	int dist = 0;
	int ans = INT_MAX;
	for (int i = pos + 1; i <= n; i++) {
		dist += a[i - 1];
		int len = max(dist, solve(i, left - 1));
		ans = min(len, ans);
	}
	return dp[pos][left] = ans;
}



int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (cin >> n >> k) {
		n++;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < nax; i++){
			for (int j = 0; j < nax; j++){
				dp[i][j] = -1;
			}
		}
		int ans = solve(0, k);
		cout << ans << endl;
	}
	return 0;
}


