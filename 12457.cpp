#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        int n; double p;
        cin >> n >> p;
        vector<vector<double>> dp(2 * n, vector<double> (2 * n));
        dp[0][0] = 1;
        for (int i = 1; i <= 2 * n - 1; i++){
            for (int j = 0; j <= 2 * n - 1; j++){
                dp[i][j] = dp[i - 1][j] * (1 - p) ;
                if (j) dp[i][j] += dp[i - 1][j - 1] * p;

            }

        }
        double ans = 0;
        for (int i = n; i <= 2 * n - 1; i++){
            ans += dp[2 * n - 1][i];
        }

        cout << setprecision(2) << fixed << ans << endl;
    }
	return 0;
}

