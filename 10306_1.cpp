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

int dp[305][305];
ii types[35];


void init(){
	for (int i = 0; i < 305; i++){
		for (int j = 0; j < 305; j++){
			dp[i][j] = 1e7;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--){
		int n, s; cin >> n >> s;
		for(int i = 0; i < n; i++) cin >> types[i].first >> types[i].second;
		init();		
		
		dp[0][0] = 0;
		for  (int i = 0; i < 305; i++){
			for (int j = 0; j < 305; j++){
				for (int k = 0; k < n; k++){
					if (i >= types[k].first && j >= types[k].second){
						dp[i][j] = min(dp[i][j], dp[i - types[k].first][j - types[k].second] + 1);
					}
				}
			}
		}
		

		
		int ans = 1e7;
		for (int i = 0; i <= s; i++){
			for (int j = 0; j <= s; j++){
				if (j * j + i * i == s * s){
					ans = min(ans, dp[i][j]);
				}
			}
		}
		if (ans >= 1e7){
			cout << "not possible" << endl;
		}
		else{
			cout << ans << endl;
		}
	}


	return 0;
}

