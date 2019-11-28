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


int s, n;
int dp[105][30005];
int types[105];
int tmp;
int solve(int i, int sum){
	if (sum == 0) {
	   return 0;
	}
	if (i < 0 || sum < 0){
		return 1e7;
	}
	
	if (dp[i][sum] != -1) return dp[i][sum];
	return dp[i][sum] = min(solve(i - 1, sum), 1 + solve(i - 1, sum - types[i]));
	
}

void init(){
	tmp = 0;
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 30005; j++) dp[i][j] = -1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--){
		init();
		cin >> s;
		cin >> n;
	
		for (int i = 0; i < n ; i++) {
			cin >> types[i];
			tmp += types[i];
		}
		
		solve(n - 1, tmp);
		for (int i = 0; i < n; i++){
			for (int j = 0; j <= tmp; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		int ans = dp[n - 1][s];		
		cout << s << " " << ans << endl;
	}


	return 0;
}

