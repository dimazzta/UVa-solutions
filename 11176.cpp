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

    int n; double p;
    while(cin >> n >> p, n){
        vector<double> p_p(n + 1);
        p_p[0] = 1;
        for (int i = 1; i < n + 1; i++){
            p_p[i] = p_p[i - 1] * p;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        for (int i = 0; i <= n; i++){
            dp[0][i] = 1;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= n; j++){
                if (j == i - 1){
                    dp[i][j] = (1.0 - p_p[i]);
                }
                else if (j >= i){
                    dp[i][j] = 1.0;
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                    if (i - j - 2 >= 0){
                        dp[i][j] -= dp[i - j - 2][j] * (1.0 - p) * p_p[j + 1];
                    }
                }
            }
        }

        double ev = 0;
        for (int i = 1; i <= n; i++){
            ev += i * (dp[n][i] - dp[n][i - 1]);
        }
        cout << setprecision(6) << fixed << ev << endl;
    }
	return 0;
}

