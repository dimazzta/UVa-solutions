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

int n, x, t, k;
int w[105];
double v[105];
double dp[105][25][1200];

double solve(int i, int sum, int taken){
	int rsum = sum + t * (n + 1);
	int f = ceil(rsum * 0.1);
	rsum += f;
	if ((rsum > (x * (n + 1))) || (taken > (2 * (n + 1)))) return -1e7;
	if ((i == k) || (taken == (2 * (n + 1)))) return 0.0;
	if (dp[i][taken][sum] != -1) return dp[i][taken][sum];
	
	else return dp[i][taken][sum] = max(solve(i + 1, sum, taken), 
	max(v[i] + solve(i + 1, sum + w[i], taken + 1), 2*v[i] + solve(i + 1, sum + 2 * w[i], taken + 2)));
}

void init(){
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 25; j++){
			for (int k = 0; k < 1200; k++){
				dp[i][j][k] = -1.0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	while(cin >> n >> x >> t >> k, n || x || t || k){
		for (int i = 0; i < k; i++){
			cin >> w[i];
			v[i] = 0;
			for (int j = 0; j < n + 1; j++){
				int tmp; cin >> tmp;
				v[i] += tmp;
			}
			v[i] = v[i] / (double)(n + 1);
		}
		init();
		double ans = solve(0, 0, 0);
		cout << setprecision(2) << fixed << ans << endl;
		
	}	


	return 0;
}

