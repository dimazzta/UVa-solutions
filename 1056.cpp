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
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int tc = 1;
	while(cin >> n >> m, n || m){
		vector<vi> mat(n, vi(n, inf));
		map<string, int> conv;
		vector<string> back(n);
		int idx = 0;
		for (int i = 0; i < m; i++){
			string s1, s2; cin >> s1 >> s2;
			if (!conv.count(s1)){
				conv[s1] = idx++;
			}
			if (!conv.count(s2)){
				conv[s2] = idx++;
			}
			mat[conv[s1]][conv[s2]] = 1;
			mat[conv[s2]][conv[s1]] = 1;
		}
		

		for (int i = 0; i < n; i++) mat[i][i] = 0;
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		int mx = 0;
		bool con = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j){
					if (mat[i][j] == inf){
						con = false;
						break;
					}
					else{
						mx = max(mx, mat[i][j]);
					}
				}
			}
		}
		if (!con){
			cout << "Network " << tc++ << ": " << "DISCONNECTED" << endl << endl;
		}
		else{
			cout << "Network " << tc++ << ": " << mx << endl << endl;
		}
		
	}
	return 0;
}


