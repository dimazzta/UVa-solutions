#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 30;
vi ts;
vi visited;
vector<vi> adj(nax);
vi cap(nax);

void topsort(int v) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		if (!visited[adj[v][i]]) {
			topsort(adj[v][i]);
		}
	}
	ts.push_back(v);
}

void clear() {
	visited.assign(nax, false);
	ts.clear();
	for (int i = 0; i < nax; i++) {
		adj[i].clear();
	}
	cap.assign(nax, 0);
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	cin.ignore();
	string tttt;
	getline(cin, tttt);
	bool kt = false;
	while (t--) {
		if (kt) cout << endl;
		kt = true;
		clear();
		string s;
		getline(cin, s);
		int topsort_start = 0;
		vi vertx;
		do {
			stringstream ss(s);
			char task;
			int c;
			string other;
			ss >> task >> c >> other;
			cap[task - 'A'] = c;
			vertx.push_back(task - 'A');
			for (int i = 0; i < other.size(); i++) {
				char tmp = other[i];
				adj[tmp - 'A'].push_back(task - 'A');
			}
			getline(cin, s);
		} while (!s.empty());

		for (int i = 0; i < vertx.size(); i++) {
			if (!visited[vertx[i]]) {
				topsort(vertx[i]);
			}
		}

		reverse(ts.begin(), ts.end());


		int max_len = 0;
		vi dp(nax);
		
		for (int i = 0; i < ts.size(); i++) {
			dp[ts[i]] = max(dp[ts[i]], cap[ts[i]]);
			for (int j = 0; j < adj[ts[i]].size(); j++) {
				int v = adj[ts[i]][j];
				dp[v] = max(dp[v], dp[ts[i]] + cap[v]);
			}
		}
		for (int i = 0; i < nax; i++) {
			max_len = max(max_len, dp[i]);
		}
		cout << max_len << endl;

	}
	return 0;
}


