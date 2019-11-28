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

ll dp[5][7501];
int c[] = {50, 25, 10, 5, 1};
int n;

ll solve(int i, int value){
	if (value == 0) return 1;
	if (i < 0 || value < 0) return 0;
	if (dp[i][value] != -1) return dp[i][value];
	else return dp[i][value] = solve(i - 1, value) + solve(i, value - c[i]);
}

void init(){
	memset(dp, -1LL, sizeof dp);
	dp[4][0] = 1LL;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	init();
	solve(4, 7500);
	while(cin >> n){
		cout << dp[4][n] << endl;
	}



	return 0;
}

