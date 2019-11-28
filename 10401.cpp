#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int convert(char s) {
	if (isdigit(s)) {
		return s - '0' - 1;
	}
	else {
		return s - 'A' - 1;
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	while (cin >> s) {
		int n = s.size();
		vector<vector<ll>> dp(n, vector<ll>(n));

		if (s[0] == '?') {
			for (int i = 0; i < n; i++) dp[i][0] = 1;
		}
		else {
			int num = s[0] - '0' - 1;
			if (num > 8) {
				num = s[0] - 'A' + 9;
			}
			dp[num][0] = 1;
		}

		for (int i = 1; i < n; i++) {
			if (s[i] == '?') {
				for (int j = 0; j < n; j++) {
					for (int k = j - 2; k >= 0; k--) {
						dp[j][i] += dp[k][i - 1];
					}
					for (int k = j + 2; k < n; k++) {
						dp[j][i] += dp[k][i - 1];
					}
				}
			}
			else {
				int num = s[i] - '0' - 1;
				if (num > 8) {
					num = s[i] - 'A' + 9;
				}

				for (int j = num - 2; j >= 0; j--) {
					dp[num][i] += dp[j][i - 1];
				}
				for (int j = num + 2; j < n; j++) {
					dp[num][i] += dp[j][i - 1];
				}
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
			ans += dp[i][n - 1];
		}
		cout << ans << endl;
	}
	return 0;
}


