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
	int x, y;
	int tc = 1;
	while(cin >> x >> y, x || y){
		vector<vector<int>> mat(105, vi(105, inf));
		for (int i = 0; i < 105; i++) mat[i][i] = 0;
		mat[x][y] = 1;
		set<int> v;
		v.insert(x);
		v.insert(y);
		while(cin >> x >> y, x || y){
			v.insert(x);
			v.insert(y);
			mat[x][y] = 1;
		}
		int n = v.size();
		for (int k = 1; k <= 100; k++){
			for (int i = 1; i <= 100; i++){
				for (int j = 1; j <= 100; j++){
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		int dist = 0;
		for (int i = 1; i <= 100; i++){
			for (int j = 1; j <= 100; j++){
				if (mat[i][j] != inf){
					dist += mat[i][j];
				}
			}
		}
		double res = (double)dist / (n * n - n);
		cout << setprecision(3) << fixed << "Case " << tc++ << ": average length between pages = " << res << " clicks" << endl;
	}
	return 0;
}


