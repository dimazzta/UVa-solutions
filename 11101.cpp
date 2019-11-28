#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};



const int nax = 2005;
const int inf = 1e9;
int m2[nax][nax];
int dist[nax][nax];

bool ok(int r, int c){
	if (r > nax || c > nax || r < 0 || c < 0) return false;
	return true;	
}

int main(){
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while(cin >> n, n){
		for (int i = 0; i < nax; i++){
			for (int j = 0; j < nax; j++){
				m2[i][j] = 0;
				dist[i][j] = inf;
			}
		}
		queue<ii> q;
		for (int i = 0; i < n; i++){
			ii a; cin >> a.first >> a.second;
			q.push(a);
			dist[a.first][a.second] = 0;
		}
		cin >> n;
		for (int i = 0; i < n; i++){
			ii a; cin >> a.first >> a.second;
			m2[a.first][a.second] = 1;
		}
		int ans = -1;
		while(!q.empty()){
			ii pos = q.front(); q.pop();
			int row = pos.first, col = pos.second;
			if (m2[row][col]) {
				ans = dist[row][col];
				break;
			}
			for (int i = 0; i < 4; i++){
				int nr = row + dr[i];
				int nc = col + dc[i];
				if (ok(nr, nc)){
					if (dist[nr][nc] == inf){
						dist[nr][nc] = dist[row][col] + 1;
						q.push({nr, nc});
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}


