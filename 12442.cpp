#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

vi a, size;
vector<bool> vis;


int dfs(int v){
	int ans = 1;
	vis[v] = true;
	if (!vis[a[v]]){
		ans = 1 + dfs(a[v]);
	}
	vis[v] = false;
	return size[v] = ans;
}

int main () {
	//freopen("out.txt", "w", stdout);
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n; cin >> n;
		a.assign(n, 0);
		size.assign(n, 0);
		vis.assign(n, false);
		for (int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			a[x - 1] = y - 1;
		}
		int mx = 0;
		int mn = 0;
		for (int  i = 0; i < n; i++){
			if (!size[i]){
				dfs(i);
			}
			if (size[i] > mx){
				mx = size[i];
				mn = i + 1;
			}
		}
		cout << "Case " << tc << ": " << mn << endl;
	}
}


