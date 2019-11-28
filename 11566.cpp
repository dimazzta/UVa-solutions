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


double dp[105][25][1200];

void init(){
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 25; j++){
			for (int k = 0; k < 1200; k++){
				dp[i][j][k] = 0.0;
			}
		}
	}
	dp[0][0][0] = 0.0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif


	int n, x, t, k;
	while(cin >> n >> x >> t >> k, n || x || t || k){
		vector<int> w(k + 1);
		vector<double> v(k + 1);
		for (int i = 1; i <= k; i++){
			cin >> w[i];
			for (int j = 0; j < n + 1; j++){
				int tmp; cin >> tmp;
				v[i] += tmp;
			}
			v[i] = v[i] / (double)(n + 1);
		}
		init();
		int total_money = x * (n + 1);
		int total_tea = t * (n + 1);
		
		for (int i = 1; i <= k; i++){
			for (int j = 0; j <= 2 * (n + 1); j++){
				for (int m = 0; m <= total_money; m++){
					dp[i][j][m] = dp[i - 1][j][m];
					if (j && m >= w[i]){
						int to_pay = m + total_tea;
						int perc = ceil(to_pay * 0.1);
						to_pay += perc;
						if (to_pay > total_money) continue;
						dp[i][j][m] = max(dp[i][j][m], v[i] + dp[i - 1][j - 1][m - w[i]]);
						if (j > 1 && m >= w[i] * 2) dp[i][j][m] = max(dp[i][j][m], 2 * v[i] + dp[i - 1][j - 2][m - 2 * w[i]]);
					}
				}
			}
		}
		double mx = 0;
		for (int i = 0; i <= total_money; i++){
			mx = max(mx, dp[k][2 * (n + 1)][i]);
		}
		cout << setprecision(2) << fixed << mx << endl;
	}

	return 0;
}

