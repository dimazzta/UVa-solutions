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

const int mod = (int)1e6;
int dp[105][105];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif


	dp[0][0] = 1;

	
	for (int i = 1; i < 105; i++){
		for (int j = 0; j < 105; j++){
			for (int k = 0; k <= j; k++){
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= mod;
			}
		}
	}
	

	while(cin >> n >> k, n && k){
 			  cout << dp[k][n] << endl;
		
	}


	return 0;
}

