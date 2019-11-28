#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int mod = 1000007;

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n; cin >> n;
		vector<vector<char>> a(n, vector<char>(n));
		vector<vector<ll>> dp(n, vector<ll>(n));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'W') dp[i][j] = 1;
			}
		}

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'B') continue;
				if (j > 0 && a[i + 1][j - 1] != 'B'){
					dp[i][j] += dp[i + 1][j - 1];
				}
				if (j < n - 1 && a[i + 1][j + 1] != 'B'){
					dp[i][j] += dp[i + 1][j + 1];
				}
				
				if (j > 0 && a[i + 1][j - 1] == 'B'){
					if (i + 2 < n && j - 2 >= 0 && a[i + 2][j - 2] != 'B'){
						dp[i][j] += dp[i + 2][j - 2];
					}
				}
				if (j < n - 1 && a[i + 1][j + 1] == 'B'){
					if (i + 2 < n && j + 2 < n && a[i + 2][j + 2] != 'B'){
						dp[i][j] += dp[i + 2][j + 2];
					}
				}
				dp[i][j] %= mod;
			}
		}
		
		
		
	//	for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += dp[0][i];
			ans %= mod;
		}
		cout << "Case " << tc << ": " << (ans % mod) << endl;
	}
	return 0;
}


