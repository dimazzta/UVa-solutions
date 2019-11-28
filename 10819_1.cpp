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

int dp[15000];
int v[105], w[105];

void init(){
	for (int i = 0; i < 15000; i++){
		dp[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int m, n; 
	while(cin >> m >> n){
		for (int i = 1; i <= n; i++){
			cin >> w[i] >> v[i];
		}
		init();
		for (int i = 1; i <= n; i++){
			for (int j = 15000; j >= 0; j--){
				if (j >= w[i]){
					if (j == w[i] || dp[j - w[i]]) dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
				}
			}
		}
		
	 	int ans = 0;
	 	if (m <= 1800){
	 		for (int i = 1; i <= m; i++)
	 		{
				ans = max(ans, dp[i]);
	 		}
	 	}
	 	else{
	 		for (int i = 1; i <= m + 200; i++)
	 		{
 				if (i <= m){
 					ans = max(ans, dp[i]);
 				}
 				else{
 					if (i > 2000){
 						ans = max(ans, dp[i]);
 					}
 				}
	 		}
	 	}

		cout << ans << endl;
	}


	return 0;
}



