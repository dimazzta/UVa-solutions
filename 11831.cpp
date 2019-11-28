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

int main(){
	int n, m, s;
	while(cin >> n >> m >> s, n || m || s){
		vector<vector<char>> a(n, vector<char>(m));
		ii pos = {0, 0};
		int dir = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
				if (a[i][j] == 'N'){
					pos = {i, j};
					dir = 0;
				}
				else if (a[i][j] == 'L'){
					pos = {i, j};
					dir = 1;
				}
				else if (a[i][j] == 'S'){
					pos = {i, j};
					dir = 2;
				}
				else if (a[i][j] == 'O'){
					pos = {i, j};
					dir = 3;
				}
			}	
		}
		int stickers = 0;
		string c;  cin >> c;
		for (int i = 0; i < s; i++){
			if (c[i] == 'D'){
				dir++;
				dir %= 4;
			}
			if (c[i] == 'E'){
				dir--;
				if (dir < 0) dir = 3;
			}
			if (c[i] == 'F'){
				int nr = pos.first + dr[dir];
				int nc = pos.second + dc[dir];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] == '#'){
					continue;
				}
				if (a[nr][nc] == '*') {
					stickers++;
					a[nr][nc] = '.';
				}
				pos.first = nr;
				pos.second = nc;
			}
		}
		cout << stickers << endl;
	}
	
	return 0;
}

