#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

vector<vi> adj;
vector<bool> vis;
vector<bool> death;
int n;

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	bool f = false;
	while(cin >> n){
		if (f) cout << endl;
		f = true;
		
		adj.clear();
		adj.resize(n);
		vis.assign(n, false);
		death.assign(n, false);
		
		for (int i = 0; i < n; i++){
			int cnt; cin >> cnt;
			if (!cnt) death[i] = true;
			for (int j=  0; j < cnt; j++){
				int x; cin >> x;
				adj[i].push_back(x);
			}
		}
		
		vi dp(n);
		dp[0] = 1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < adj[i].size(); j++){
				dp[adj[i][j]] += dp[i];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) if (death[i]) cnt += dp[i];
		cout << cnt << endl;
	}
	return 0;
}


