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

int dist[11][11];
int dp[11][1 << 11];
int n;

int solve(int idx, int mask){
	if (mask == ((1 << (n + 1)) - 1)){
		return dist[idx][0];
	}
	if (dp[idx][mask] != -1) return dp[idx][mask];
	
	int mn = INT_MAX;
	for (int i = 1; i <= n; i++){
		if ((mask & (1 << i)) == 0){
			mn = min(mn, dist[idx][i] + solve(i, mask | (1 << i)));
		}
	}
	return dp[idx][mask] = mn;
}

void init(){
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < (1 << 11); j++){
			dp[i][j] = -1;
		}
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
		int x, y; cin >> x >> y;
		int sX, sY; cin >> sX >> sY;
		init();
		cin >> n;
		vii coords(n + 1);
		for (int i = 1; i <= n; i++){
			cin >> coords[i].first >> coords[i].second;
		}
		coords[0].first = sX;
		coords[0].second = sY;
		
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				if (i != j) {
					dist[i][j] = abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
				}
				
			}
		}
		int ans = solve(0, 1);
		cout << "The shortest path has length " << ans << endl;
	}


	return 0;
}

