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

int solve(int num, int cnt){
	if (cnt == 1) return 1;
	if (dp[num][cnt] != -1) return dp[num][cnt];
	int sum = 0;
	for (int j = 0; j <= num; j++){
		sum += solve(num - j, cnt - 1);
		sum %= mod;
	}
	return dp[num][cnt] = sum;
}


void init(){
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 105; j++){
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
	
	

	while(cin >> n >> k, n && k){
		init();
		int ans = solve(n, k);	
		cout << ans << endl;
	}


	return 0;
}

