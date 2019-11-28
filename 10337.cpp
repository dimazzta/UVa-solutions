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

int a[10][1001], dp[10][1001];

void init(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 1001; j++){
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
	bool st = false;
	while(t--){

		st = true;
		int x; cin >> x;
		for (int i = 9; i >= 0; i--){
			for (int j = 0; j < x / 100; j++){
				cin >> a[i][j];
			}
		}
		init();
		for (int i = 0; i < x / 100; i++){
			for (int j = 0; j < 10; j++){
				dp[j][i + 1] = min(dp[j][i + 1], 30 - a[j][i] + dp[j][i]);
				if (j > 0) dp[j - 1][i + 1] = min(dp[j - 1][i + 1], 20 - a[j][i] + dp[j][i]);
				if (j < 9) dp[j + 1][i + 1] = min(dp[j + 1][i + 1], 60 - a[j][i] + dp[j][i]);
			}
		}
		
		int ans = dp[0][x / 100];
		cout << ans << endl << endl;
		
	}



	return 0;
}

