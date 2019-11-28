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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vi> a(n, vi(n)), b(2 * n, vi(2 * n)), dp(2 * n, vi(2 * n));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> b[i][j];
				b[i + n][j] = b[i][j];
				b[i][j + n] = b[i][j];
				b[i + n][j + n] = b[i][j];
			}
		}
		
		for (int i = 0; i < 2 * n; i++){
			int sum = 0;
			for (int j = 0; j < 2 * n; j++){
				sum += b[i][j];
				dp[i][j] = sum;
			}
		}
		
		
		int mx = -INT_MAX;
		for (int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				
				for (int k = 0; k < n; k++){
					int total = 0;
					for (int k1 = 0; k1 < n; k1++){
						int sum = dp[k + k1][i + j];
						if (i > 0) sum -= dp[k + k1][i - 1];
						total += sum;
						mx = max(total, mx);
						if (total < 0) total = 0;
					}
				}
			}
		}
		
		cout << mx << endl;
	}



	return 0;
}

