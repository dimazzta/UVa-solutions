#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int n; 
	while(cin >> n, n){
		int m; cin >> m;
		vector<vector<int>> a(n);
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		vi color(n);
		queue<int> q;
		q.push(0);
		color[0] = 1;
		bool b = true;
		while(!q.empty() && b){
			int v = q.front(); q.pop();
			for (int i = 0; i < a[v].size(); i++){
				int ncolor = color[v] == 1 ? 2 : 1;
				if (!color[a[v][i]]){
					q.push(a[v][i]);
					color[a[v][i]] = ncolor;
				}
				else if (color[a[v][i]] != ncolor){
					b = false;
					break;
				}
			}
		}
		cout << (b ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
	}
	return 0;
}


