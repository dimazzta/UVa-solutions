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
	

	int n;
	while(cin >> n, n){
		vector<vi> y_mat(2 * n, vi(2 * n, inf));
		vector<vi> o_mat(2 * n, vi(2 * n, inf));
		
		char a, b, c, d;
		int cost;
		for (int i = 0; i < n; i++){
			cin >> a >> b >> c >> d >> cost;
			int x = c - 65;
			int y = d - 65;
			if (a == 'Y'){
				y_mat[x][y] = cost;
				if (b == 'B') y_mat[y][x] = cost;
			}
			else{
				o_mat[x][y] = cost;
				if (b == 'B') o_mat[y][x] = cost;
			}
		}
		
		char e, f; cin >> e >> f;
		int source = e - 65;
		int dest = f - 65;
		for (int k = 0; k < 2 * n; k++){
			for (int i = 0; i < 2 * n; i++){
				for (int j = 0; j < 2 * n; j++){
					y_mat[i][j] = min(y_mat[i][j], y_mat[i][k] + y_mat[k][j]);
					o_mat[i][j] = min(o_mat[i][j], o_mat[i][k] + o_mat[k][j]);
				}
			}
		}
		for (int i = 0; i < 2 * n; i++){
			y_mat[i][i] = o_mat[i][i] = 0;
		}
		vi best_pos;
		int min_val = inf;
		for (int i = 0; i < 2 * n; i++){
			if (y_mat[source][i] + o_mat[dest][i] < min_val){
				min_val = y_mat[source][i] + o_mat[dest][i];
				best_pos.clear();
				best_pos.push_back(i);
			}
			else if (y_mat[source][i] + o_mat[dest][i] == min_val){
				best_pos.push_back(i);
			}
		}
		if (min_val == inf){
			cout << "You will never meet." << endl;
		}
		else {
			cout << min_val;
			sort(best_pos.begin(), best_pos.end());
			for (int i = 0; i < best_pos.size(); i++){
				cout << " " << (char)(best_pos[i] + 65);
			}
			cout << endl;
		}
		
	}
	return 0;
}


