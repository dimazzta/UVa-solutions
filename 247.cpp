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
vi ids;
vi low;
vector<bool> stacked;
stack<int> st;
int cntr;
vector<set<string>> cc;
vector<string> from;

void dfs(int v) {
	ids[v] = low[v] = cntr++;
	st.push(v);
	stacked[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i];
		if (!ids[u]) dfs(u);
		if (stacked[u]) low[v] = min(low[v], low[u]);
	}
	if (low[v] == ids[v]) {
		set<string> s;
		while (true) {
			int sv = st.top(); st.pop();
			stacked[sv] = false;
			s.insert(from[sv]);
			if (sv == v) break;
		}
		cc.push_back(s);
	}
}


int main() {
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	int tc = 1;
	while (cin >> n >> m, n || m) {
		ids.assign(n, 0);
		low.assign(n, 0);
		from.resize(n);
		adj.clear();
		adj.resize(n);
		stacked.assign(n, 0);
		st = stack<int>();
		cntr = 1;
		cc.clear();
		
		map<string, int> to;
		int j = 0;
		for (int i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			int s1i, s2i;
			if (!to.count(s1)) {
				s1i = j++;
				to[s1] = s1i;
			}
			else {
				s1i = to[s1];
			}

			if (!to.count(s2)) {
				s2i = j++;
				to[s2] = s2i;
			}
			else {
				s2i = to[s2];
			}
			from[s2i] = s2;
			from[s1i] = s1;
			adj[s1i].push_back(s2i);
		}

		for (int i = 0; i < n; i++) {
			if (!ids[i]) dfs(i);
		}


		cout << "Calling circles for data set " << tc++ << ":";
		if (cc.size()) cout << endl;
		
		for (int i = 0; i < cc.size(); i++) {
			bool f = false;
			for (auto &s:cc[i]) {
				if (f) cout << ", ";
				f = true;
				cout << s; 
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}


