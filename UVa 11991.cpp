#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

int main() {
	int n, m;
	while (cin >> n >> m) {
		uw_graph graph(1000005);
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			graph[k].push_back(i + 1);
		}
		for (int i = 0; i < m; i++) {
			int k, u;
			cin >> k >> u;
			if (graph[u].size() >= k) {
				cout << graph[u][k - 1] << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
	}
}
