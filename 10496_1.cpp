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


int dp[1 << 11][11];
void init(){
	for (int i = 0; i < (1 << 11); i++){
		for (int j = 0; j < 11; j++){
			dp[i][j] = 1e7;
			
		}
	}
	for (int i = 0; i < 11; i++){
		dp[1 << i][i] = 0;
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
		int x, y; cin >> x >> y;
		int sX, sY; cin >> sX >> sY;
		int n; cin >> n;
		vii coords(n + 1);
	 	coords[0].first = sX;
	 	coords[0].second = sY;
	 	for (int i = 1; i <= n; i++) cin >> coords[i].first >> coords[i].second;
	 	int dist[11][11];
	 	for (int i = 0; i <= n; i++){
	 		for (int j = 0; j <= n; j++){
	 			if (i != j){
	 				dist[i][j] = abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
	 			}
	 			else dist[i][j] = 0;
	 		}
	 	}
	
	 	init();
    	for (int i = 0; i < (1 << (n + 1)); i++){
    		for (int j = 0; j <= n; j++){
    			if ((i & (1 << j)) == 0) continue;
    			for (int k = 1; k <= n; k++){
    				if ((i & (1 << k)) != 0){
    					dp[i][k] = min(dp[i][k], dist[j][k] + dp[i ^ (1 << k)][j]);
    				}
    			}
    		}
    	}
  
    	int ans = 1e7;
    	for (int i = 1; i <= n; i++){
    		ans = min(ans, dist[i][0] + dp[(1 << (n + 1)) - 1][i]);
    	}
		
    	cout <<  "The shortest path has length " << ans << endl;
	}


	return 0;
}

