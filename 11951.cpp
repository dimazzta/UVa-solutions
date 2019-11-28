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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int t; cin >> t;
	for (int test = 1; test <= t; test++){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<ll>> dp(n, vector<ll>(m));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int x; cin >> x;
				dp[i][j] = x;
				if (i > 0) dp[i][j] += dp[i - 1][j];
				if (j > 0) dp[i][j] += dp[i][j - 1];
				if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
				//cout << dp[i][j] << " ";
			}
			//cout << endl;
		}
		ll mn = LLONG_MAX;
		int mx_area = -1;
		bool did = false;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				for (int i1 = i; i1 < n; i1++){
					for (int j1 = j; j1 < m; j1++){
						ll sum = dp[i1][j1];
						if (i > 0) sum -= dp[i - 1][j1];
						if (j > 0) sum -= dp[i1][j - 1];
						if (i > 0 && j > 0) sum += dp[i-1][j-1];
						if (sum > k){
							break;
						}
						else{
							did = true;
							int area = (i1 - i + 1) * (j1 - j + 1);
							if (area > mx_area){
								mn = sum;
								mx_area = area;
							}
							else if (area == mx_area){
								if (sum < mn){
									mn = sum;
								}
							}
						}
					}
					
				}
			}
		}
		if (!did) {
			mx_area = 0;
			mn = 0;
		}
		cout << "Case #" << test << ": " << mx_area << " " << mn << endl;
	}


	return 0;
}

