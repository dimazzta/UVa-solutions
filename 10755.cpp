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

	int t;
	cin >> t;
	bool tr = false;
	while(t--){
		if (tr) cout << endl;
		tr = true;
		int a, b, c; cin >> a >> b >> c;
		ll cube[21][21][21], dp[21][21][21];
		
		for (int i = 0; i < a; i++){
			for (int j = 0; j < b; j++){
				for (int k = 0; k < c; k++){
					dp[i][j][k] = 0;
					cin >> cube[i][j][k];
					dp[i][j][k] += cube[i][j][k];
					if (k > 0) dp[i][j][k] += dp[i][j][k-1];
					if (j > 0) dp[i][j][k] += dp[i][j - 1][k];
					if (k > 0 && j > 0) dp[i][j][k] -= dp[i][j-1][k-1];
				}
			}
		}

		
		ll mx = -LLONG_MAX;
		for (int i = 0; i < b; i++){
			for (int j = 0; j < c; j++){
				for (int i1 = i; i1 < b; i1++){
					for (int j1 = j; j1 < c; j1++){
						ll total = 0;
						for (int k = 0; k < a; k++){
							ll sum = dp[k][i1][j1];
							if (i > 0) sum -= dp[k][i - 1][j1];
							if (j > 0) sum -= dp[k][i1][j - 1];
							if (i > 0 && j > 0) sum += dp[k][i - 1][j - 1];
							total += sum;
							mx = max(total, mx);
							if (total < 0) total = 0;
						}
					}
				}
			}
		}
		cout << mx << endl;
	}


	return 0;
}

