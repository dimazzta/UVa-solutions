#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e7;

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){

		int n, m;
		cin >> n >> m;
		
		vector<vi> mat(n + m, vi(n + m, inf));
		for (int i = 0; i < n + m; i++) mat[i][i] = 0;
		
		int k = n;
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			mat[x][k] = 1;
			mat[k][y] = 1;
			mat[k][x] = 1;
			mat[y][k] = 1;
			k++;
		}
		
		for (int u = 0; u < n + m; u++){
			for (int i = 0; i < n + m; i++){
				for (int j = 0; j < n + m; j++){
					mat[i][j] = min(mat[i][j], mat[i][u] + mat[u][j]);
				}
			}
		}
	
		int ans = inf;
		for (int i = 0; i < n + m; i++){
			int mx = 0;
			for (int j = 0; j < n; j++){
				mx = max(mx, mat[i][j]);
			}
			ans = min(ans, mx);
		}
		cout << "Case #" << tc << ":" << endl;
		cout << ans << endl;
		cout << endl;
	}
	return 0;
}


