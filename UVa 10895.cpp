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
		mi mat(n + 1, vector<int>(m + 1));
		w_graph graph(n + 1);
		w_graph result(m + 1);

		for (int i = 0; i < n; i++) {
			int r;
			cin >> r;
			for (int j = 0; j < r; j++) {
				int c;
				cin >> c;
				graph[i + 1].push_back({ c, 0 });
			}
			for (int j = 0; j < r; j++) {
				int c;
				cin >> c;
				graph[i + 1][j].second = c;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				result[graph[i][j].first].push_back({ i,graph[i][j].second });
			}
		}
		cout << m << " " << n << endl;
		for (int i = 1; i <= m; i++) {
			cout << result[i].size();
			if (result[i].size()) cout << " ";
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j].first;
				if (j != result[i].size() - 1) cout << " ";
			}
			cout << endl;
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j].second;
				if (j != result[i].size() - 1) cout << " ";
			}
			cout << endl;
		}

	}
	
}
