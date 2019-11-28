#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e8;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n, m; cin >> n >> m;
		vector<vector<int>> mat(n, vector<int>(n, inf));
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			mat[x][y] = 1;
			mat[y][x] = 1;
		}
		for (int i = 0; i < n; i++) mat[i][i] = 0;
		
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		int s, d;  cin >> s >> d;
		int mx = 0;
		for (int i = 0; i < n; i++){
			mx = max(mat[s][i] + mat[i][d], mx);
		}
		cout << "Case " << tc << ": " << mx << endl;
	}
	return 0;
}


