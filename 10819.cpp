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

int dp[105][(int)1.5e4];
int w[105], v[105];
int m, n;

int take(int i, int sum){
	if (sum > m && m <= 1800) return -1e5;
	if (sum - m > 200) return -1e5;
	if (i == n) {
		if (sum > m){
			if (sum > 2000) return 0;
			else return -1e5;
		}
		return 0;
	}
	
	if (dp[i][sum] == -1){
	   return dp[i][sum] = max(take(i + 1, sum), v[i] + take(i + 1, sum + w[i]));
	}
	else return dp[i][sum];
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif


	while(cin >> m >> n){
		for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
		
		for (int i = 0; i < 105; i++){
			for (int j = 0; j < (int)1.5e4; j++){
				dp[i][j] = -1;
			}
		}
		
		int mx = take(0, 0);
			
		cout << mx << endl;
		
	}


	return 0;
}

