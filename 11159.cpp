#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 205;
vector<vi> adj(nax);
vector<bool> vis(nax);
vi match(nax);

int aug(int l){
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int i = 0; i < adj[l].size(); i++){
		int r = adj[l][i];
		if (match[r] == -1 || aug(match[r])){
			match[r] = l; return 1;
		}
	}
	return 0;
}

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int cnt1, cnt2;
		cin >> cnt1;
		vi s1, s2;
		for (int i = 0; i < cnt1; i++){
			int x; cin >> x;
			s1.push_back(x);
		}
		cin >> cnt2;
		for (int i = 0; i < cnt2; i++){
			int x; cin >> x;
			s2.push_back(x);
		}
		
		for (int i = 0; i < nax; i++){
			adj[i].clear();
		}
		
		for (int i = 0; i < cnt1; i++){
			for (int j = 0; j < cnt2; j++){
				if (s2[j] == 0 || (s1[i] && (s2[j] % s1[i] == 0))){
					adj[i].push_back(cnt1 + j);
				}
			}
		}
		
		int mbp = 0;
		match.assign(nax, -1);
		for (int i = 0; i < cnt1; i++){
			vis.assign(nax, false);
			mbp += aug(i);
		}
		cout << "Case " << tc << ": " << mbp << endl;
	}
	return 0;
}


