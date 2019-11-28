#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

char a[105][105];
int n;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void fill(int r, int c, char replace, char replace1, char with){
	if (r < 0 || c < 0 || r >= n || c >= n){
		return;
	}
	if (a[r][c] != replace && a[r][c] != replace1) return;
	a[r][c] = with;
	for (int i = 0; i < 4; i++){
		fill(r + dr[i], c + dc[i], replace, replace1, with);
	}
}

int main(){
	//freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (a[i][j] == 'x'){
					cnt++;
					fill(i, j, 'x', '@', '.');
				}
			}
		}
		cout << "Case " << tc << ": " << cnt << endl;
	}
	return 0;
}

