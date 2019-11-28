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


int dp[35][1005];
int path[35][1005];
int n, C, t;
int w[35], v[35];
vi seq;

int solve(int i, int sum){
	if (sum > t) return -1e7;
	if (i == n) return 0;
	if (dp[i][sum] != -1) return dp[i][sum];
	else {
		int dont_take = solve(i + 1, sum);
		int take = v[i] + solve(i + 1, sum + 3 * C * w[i]);
		if (dont_take >= take){
			path[i][sum] = 1;
		}
		else path[i][sum] = 2;
		return dp[i][sum] = max(take, dont_take);
	}
}

void restore(int i, int sum){
	if (i == n) return;
	if (path[i][sum] == 2){
		seq.push_back(i);
		restore(i + 1, sum + 3 * C * w[i]);
	}
	else{
		restore(i + 1, sum);
	}
}



void init(){
	seq.clear();
	for (int i = 0; i < 35; i++){
		for (int j = 0; j < 1005; j++){
			dp[i][j] = -1;
			path[i][j] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	bool fff = false;
	while(cin >> t >> C){
		if (fff) cout << endl;
		fff = true;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
		init();
		int ans = solve(0, 0);
		restore(0, 0);
		cout << ans << endl;
		cout << seq.size() << endl;
		for (int i = 0; i < seq.size(); i++){
			cout << w[seq[i]] << " " << v[seq[i]] << endl;
		}
	}


	return 0;
}

