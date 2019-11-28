#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

ii dw[] = { { -1, 0 },{ 0, -1 },{ 1, -1 },{ 1, 0 },{ 0, 1 } };

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N = 100005;
	vector<ii> ans(N);
	ans[1] = { 0, 0 };
	ans[2] = { 0, 1 };
	int d = 0;
	int layer = 1;
	for (int i = 3; i < N; ) {
		for (int j = 0; j < layer; j++) {
			ans[i] = { ans[i - 1].first + dw[d].first, ans[i - 1].second + dw[d].second };
			i++;
			if (i >= N) break;
		}
		d++;
		if (d == 5) {
			ans[i] = { ans[i - 1].first + dw[d - 1].first, ans[i - 1].second + dw[d - 1].second };
			i++;
			if (i >= N) break;
			for (int j = 0; j < layer; j++) {
				ans[i] = { ans[i - 1].first - 1, ans[i - 1].second + 1 };
				i++;
				if (i >= N) break;
			}
			d = 0;
			layer++;
		}

	}
	int n;
	while (cin >> n) {
		cout << ans[n].first << " " << ans[n].second << endl;
	}
	return 0;
}


