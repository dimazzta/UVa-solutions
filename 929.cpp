#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e9;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<int>> a(n, vi(m));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		priority_queue<pair<int, ii>> pq;
		vector<vector<int>> dist(n, vi(m, inf));
		dist[0][0] = a[0][0];
		pq.push({-a[0][0], {0, 0}});
		while(!pq.empty()){
			int row, col, d;
			pair<int, ii> vert = pq.top(); pq.pop();
			row = vert.second.first, col = vert.second.second, d = -vert.first;
			if (dist[row][col] < d) continue;
			for (int i = 0; i < 4; i++){
				int nr = row + dr[i];
				int nc = col + dc[i];
				if (nr >= 0 && nr < n && nc >= 0 && nc < m){
					if (dist[nr][nc] > d + a[nr][nc]){
						dist[nr][nc] = d + a[nr][nc];
						pq.push({-dist[nr][nc], {nr, nc}});
					}
				}
			}
		}
		cout << dist[n - 1][m - 1] << endl;
	}
	return 0;
}


