#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;


pair<int, double> points[13];
double dp[13][1 << 13];
double dist[51][51];
int p;

double solve(int idx, int mask)
{
	if ((mask == (1 << (p + 1)) - 1)) {
		return dist[points[idx].first][points[0].first];
	}
	if (dp[idx][mask] <= 1e19) return dp[idx][mask];

	double mn = 1e20;
	for (int i = 1; i <= p; i++) {
		if ((mask & (1 << i)) == 0) {
			double call = solve(i, mask | (1 << i));
			mn = min(mn, dist[points[idx].first][points[i].first] - points[idx].second + call);
		}
	}
	mn = min(mn, dist[points[idx].first][points[0].first] - points[idx].second);
	return dp[idx][mask] = mn;
}

void init() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < (1 << 13); j++) {
			dp[i][j] = 1e20;
		}
	}
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			dist[i][j] = 1e20;
			if (i == j) dist[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef DEBUG
	freopen("out.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int v, e; cin >> v >> e;
		init();
		for (int i = 0; i < e; i++) {
			int v1, v2;
			double value;
			cin >> v1 >> v2 >> value;
			dist[v1][v2] = dist[v2][v1] = min(value, min(dist[v1][v2], dist[v2][v1]));
		}

		cin >> p;
		points[0].first = 0; points[0].second = 0.0;
		for (int i = 1; i <= p; i++) {
			cin >> points[i].first >> points[i].second;
		}



		for (int k = 0; k <= v; k++) {
			for (int i = 0; i <= v; i++) {
				for (int j = 0; j <= v; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		


		double ans = solve(0, 1);
		if (ans < 0) {
			ans = abs(ans);
			cout << "Daniel can save $" << setprecision(2) << fixed << ans << endl;
		}
		else {
			cout << "Don’t leave the house" << endl;
		}
		

	}

	return 0;
}

