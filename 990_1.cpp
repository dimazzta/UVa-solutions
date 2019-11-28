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


int dp[35][1005];
int path[35][1005];
int w[35], v[35];
int C, t;
void init(){
	for (int i = 0; i < 35; i++){
		for (int j = 0; j < 1005; j++){
			dp[i][j] = 0;
			path[i][j] = 1;
		}
	}
}

void restore(int i, int sum, vi & ans){
	if (i < 0) return;
	if (path[i][sum] == 2){
		ans.push_back(i);
		restore(i - 1, sum - 3 * C * w[i], ans);
	} 
	else{
		restore(i - 1, sum, ans);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	bool fff = false;
	while(cin >> t >> C){
		if (fff) cout << endl;
		fff = true;
		int n; cin >> n;
	
		for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
		init();
		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= t; j++){
				dp[i][j] = dp[i - 1][j];
				if (j >= 3 * C * w[i]){
					int take = v[i] + dp[i - 1][j - 3 * C * w[i]];
					if (take > dp[i][j]){
						dp[i][j] = take;
						path[i][j] = 2;
					} 
				}
			}
		}
		cout << dp[n][t] << endl;
		vi ans;
		restore(n, t, ans);
		reverse(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) cout << w[ans[i]] << " " << v[ans[i]] << endl;
	}


	return 0;
}

