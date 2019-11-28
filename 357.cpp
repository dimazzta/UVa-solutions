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

ll dp[6][30005];
int c[] = {1, 5, 10, 25, 50};
void init(){
	memset(dp, 0LL, sizeof(dp));
	dp[0][0] = 1LL;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	init();
	for (int i = 1; i <= 5; i++){
		for (int j = 0; j <= 30000; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= c[i - 1]){
				dp[i][j] += dp[i][j - c[i - 1]];
			}
		}
	}

	int n;
	while(cin >> n){
		ll ans = dp[5][n];
	
		if (ans == 1){
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
		else
			cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;
	}


	return 0;
}

