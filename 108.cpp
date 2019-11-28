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

	int n; cin >> n;
	vector<vi> a(n, vi(n)), dp(n, vi(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j > 0)
			    dp[i][j] = dp[i][j - 1] + a[i][j];
            else
            	dp[i][j] = a[i][j];
		}
	}
	int mx = -INT_MAX;
	for (int u = 0; u < n; u++){
		for (int v = u; v < n; v++){
			int total = 0;
			for (int i = 0; i < n; i++){
				int one_d_sum = 0;
				if (u != 0){
				   	one_d_sum = dp[i][v] - dp[i][u - 1];
				}
				else{
					one_d_sum = dp[i][v];
				}
				total += one_d_sum;
				mx = max(mx, total);
				if (total < 0) total = 0;
			}
		}
	}
	cout << mx << endl;

	return 0;
}

