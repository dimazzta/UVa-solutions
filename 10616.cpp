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

	ll dp[205][15][25];
	int n, q;
	int st = 1;
	while(cin >> n >> q, n && q){
		cout << "SET " << st++ << ":" << endl;
		vi a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
		for (int t = 1; t <= q; t++){
			int d, m;
			cin >> d >> m;
			for (int i = 0; i < 205; i++){
				for (int j = 0; j < 15; j++){
					for (int k = 0; k < 25; k++){
						dp[i][j][k] = 0;
						if (j == 0 && i == 0 && k == 0){
							dp[i][j][k] = 1;
						}
					}
				}
			}
			
			for (int i = 1; i <= n; i++){
				for (int j = 0; j <= m; j++){
					for (int k = 0; k < d; k++){
						dp[i][j][k] = dp[i - 1][j][k];
						if (j){
							int sm = (k - a[i]) % d;
							if (sm < 0) sm += d;
							dp[i][j][k] += dp[i - 1][j - 1][sm];
							
						}
					}
				}
			}
			
			cout << "QUERY " << t << ": " <<  dp[n][m][0] << endl;
		}
	}
	
	return 0;
}

