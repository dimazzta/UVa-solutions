#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int n, m;
char a[25][25];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int fill(int r, int c, char replace, char with){
	if (r < 0 || r >= n){
		return 0;
	}
	if (c >= m) c = 0;
	if (c < 0) c = m - 1;
	
	if (a[r][c] != replace) return 0;
	a[r][c] = with;
	int ans = 1;
	for (int i = 0; i < 4; i++){
		ans += fill(r + dr[i], c + dc[i], replace, with);
	}
	return ans;
}

void print(){
	for (int i =0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}

int main(){
	//freopen("out.txt", "w", stdout);
	
	while(cin >> n >> m){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int x, y; cin >> x >> y;
		char land = a[x][y];
		char water = '.';
		if (land == '.') water = '!';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i][j] != land) {
					water = a[i][j];
					break;
				}
			}
		}
		
		
		fill(x, y, land, water);
		//print();
		int mx = 0;
		for(int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i][j] == land){
					mx = max(mx, fill(i, j, land, water));
					//print();
				}
			}
		}
		cout << mx << endl;
	}
	
	
	
	return 0;
}

