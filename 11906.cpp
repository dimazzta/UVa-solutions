#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int a[205][205];
int visited[205][205];
int r, c, n, m;

bool can(int x, int y){
	if (x < 0 || x >= r || y < 0 || y >= c || a[x][y] == -100){
		return 0;
	}
	return 1;
}

void dfs(int x, int y){
	visited[x][y] = 1;
	int cnt = 0;

	if (n == 0){
		if (can(x, y - m) ){
			cnt++;
			if (!visited[x][y - m])
				dfs(x, y - m);
		}
		if (can(x, y + m) ){
			cnt++;
			if (!visited[x][y + m])
				dfs(x, y + m);
		}
		if (can(x - m, y)){
			cnt++;
			if (!visited[x - m][y])
				dfs(x - m, y);
		}
		if (can(x + m, y)){
			cnt++;
			if (!visited[x + m][y])
				dfs(x + m, y);
		}
	}

	else if (m == 0){
		if (can(x, y - n) ){
			cnt++;
			if (!visited[x][y - n])
				dfs(x, y - n);
		}
		if (can(x, y + n) ){
			cnt++;
			if (!visited[x][y + n])
				dfs(x, y + n);
		}
		if (can(x - n, y)){
			cnt++;
			if (!visited[x - n][y])
				dfs(x - n, y);
		}
		if (can(x + n, y)){
			cnt++;
			if (!visited[x + n][y])
				dfs(x + n, y);
		}
	}
	
	else if (n == m){
		if (can(x - n, y - m) ){
			cnt++;
			if (!visited[x - n][y - m])
				dfs(x - n, y - m);
		}
		if (can(x - n, y + m) ){
			cnt++;
			if (!visited[x - n][y + m])
				dfs(x - n, y + m);
		}
		if (can(x + n, y - m)){
			cnt++;
			if (!visited[x + n][y - m])
				dfs(x + n, y - m);
		}
		if (can(x + n, y + m)){
			cnt++;
			if (!visited[x + n][y + m])
				dfs(x + n, y + m);
		}
	}
	else{
		if (can(x - n, y - m) ){
			cnt++;
			if (!visited[x - n][y - m])
				dfs(x - n, y - m);
		}
		
		if (can(x - n, y + m)){
			cnt++;
			if (!visited[x - n][y + m])
				dfs(x - n, y + m);
		}
		
		if (can(x + n, y - m)){
			cnt++;
			if (!visited[x + n][y - m])
				dfs(x + n, y - m);
		}
	
	
		if (can(x + n, y + m)){
			cnt++;
			if (!visited[x + n][y + m])
				dfs(x + n, y + m);
		}
	
	
		if (can(x - m, y - n)){
			cnt++;
			if (!visited[x - m][y - n])
				dfs(x - m, y - n);
		}
	
		if (can(x - m, y + n)){
			cnt++;
			if (!visited[x - m][y + n])
				dfs(x - m, y + n);
		}
	
		
		if (can(x + m, y - n)){
			cnt++;
			if (!visited[x + m][y - n])
				dfs(x + m, y - n);
		}
		
		if (can(x + m, y + n)){
			cnt++;
			if (!visited[x + m][y + n])
				dfs(x + m, y + n);
		}
	}

	a[x][y] = cnt;
}



int main(){
	//freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> r >> c >> m >> n;
		int w; cin >> w;
		for (int i = 0; i < 205; i++){
			for (int j = 0; j < 205; j++){
				a[i][j] = -1; visited[i][j] = 0;
			}
		}
		for (int i = 0; i < w; i++) {
			int x, y;
			cin >> x >> y;
			a[x][y] = -100;
		}
		
		dfs(0, 0);
	

		int ec = 0, oc = 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				//cout << a[i][j] << " ";
				if (a[i][j] != -100 && a[i][j] != -1){
					if (a[i][j] % 2 == 0) ec++;
					else oc++;
				}
			}
			//cout << endl;
		}
		cout << "Case " << tc << ": " << ec << " " << oc << endl;
	}
	return 0;
}

