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

int dp[105][30005];
int types[105];


void init(){
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 30005; j++){
			dp[i][j] = 1e7;
		}
	}
	dp[0][0] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--){
		int s; cin >> s;
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> types[i];
		}
		init();
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < 30005; j++){
				dp[i][j] = dp[i - 1][j];
				if (j >= types[i]){
					dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - types[i]]);
				}
			}
		}
		int ans = dp[n][s];
		int cnt = s;
		if (ans >= 1e7){
			for (int i = 1; i <= 20000; i++){
				if (dp[n][s + i] < 1e7){
					ans = dp[n][s + i];
					cnt = s + i;
					break;
				}
			}
		}
		cout << cnt << " " << ans << endl;
		
	}


	return 0;
}

