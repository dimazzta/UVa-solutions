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

int n, q, m, d;
int a[205];
int dp[205][15][25];

ll take(int i, int sum, int taken){
    if (taken > m) return 0;
	if (i == n) {
        if (sum == 0 && taken == m) return 1;
        return 0;
	}

	if (dp[i][taken][sum] != -1) return dp[i][taken][sum];
	else{
		int new_sum = (sum + a[i]) % d;
		if (new_sum < 0) new_sum += d;
		return dp[i][taken][sum] = take(i + 1, new_sum, taken + 1) + take(i + 1, sum, taken);
	}
}
void init(){
	for (int i = 0; i < 205; i++){
		for (int j = 0; j < 15; j++){
			for (int k = 0; k < 25; k++) dp[i][j][k] = -1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	int st = 1;
	while(cin >> n >> q, n && q){
		cout << "SET " << st++ << ":" << endl;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < q; i++){
			init();
			cin >> d >> m;
			ll ans = take(0, 0, 0);
			
			cout << "QUERY " << i + 1 << ": " << ans << endl;
		}
	};


	return 0;
}

