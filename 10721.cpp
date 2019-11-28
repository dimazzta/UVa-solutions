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


ll dp[52][52];

void init(){
	for (int i = 1; i <= 51; i++){
		for (int j = 1; j <= 51; j++){
			dp[i][j] = 0;
			if (i == 1) dp[0][0] = 1;
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int n, k, m;
	while(cin >> n >> k >> m){
		init();
		for (int i = 1; i <= k; i++){
			for (int j = 1; j <= n; j++){
				for (int s = 1; s <= m; s++){
					if (j >= s){
						dp[i][j] += dp[i - 1][j - s];
					}
					
				}
			}
		}
		cout << dp[k][n] << endl;
	}


	return 0;
}

