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
ii types[45];
int n, s;

int solve(int x, int y){
	if (x < 0 || y < 0) return 1e7;
	if (x == 0 && y == 0) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	int mn = INT_MAX;
	for (int i = 0; i < n; i++){
		mn = min(mn, 1 + solve(x - types[i].first, y - types[i].second));
	}
	return dp[x][y] = mn; 
}

void init(){
	memset(dp, -1, sizeof dp);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--){
		cin >> n >> s;
		for (int i = 0; i < n; i++){
			cin >> types[i].first >> types[i].second;
		}
		init();
		int mn = 1e7;
		for (int i = 0; i <= s; i++){
			for (int j = 0; j <= s; j++){
				if (j * j + i * i == s * s){
					mn = min(mn, solve(i, j));
				}
			}
		}
		if (mn >= 1e7){
			cout << "not possible" << endl;
		}
		else{
			cout << mn << endl;
		}
		
	}



	return 0;
}

