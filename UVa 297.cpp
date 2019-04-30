#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;
typedef tuple<int, int, int> iii;

mi grid(33, vi(33));

int solve(string & s, int i1, int x1, int x2, int y1, int y2) {

	if (s[i1] == 'e') {
		return i1;
	}
	if (s[i1] == 'f') {
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				grid[j][i] = 1;
			}
		}
		return i1;
	}
	if (s[i1] == 'p') {
		int q1 = solve(s, i1 + 1, (x1 + x2) / 2 + 1, x2, y1, (y1 + y2) / 2);
		int q2 = solve(s, q1 + 1, x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
		int q3 = solve(s, q2 + 1, x1, (x1 + x2) / 2, (y1 + y2) / 2 + 1, y2);
		int q4 = solve(s, q3 + 1, (x1 + x2) / 2 + 1, x2, (y1 + y2) / 2 + 1, y2);
		return q4;
	}
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		grid.assign(33, vi(33, 0));
		string s, s1;
		cin >> s >> s1;

		solve(s, 0, 1, 32, 1, 32);
		solve(s1, 0, 1, 32, 1, 32);


		int cnt = 0;
		for (int i = 0; i <= 32; i++) {
			for (int j = 0; j <= 32; j++) {
				cnt += grid[i][j];
			}
		}
		cout << "There are " << cnt << " black pixels."<< endl;
	}

}
