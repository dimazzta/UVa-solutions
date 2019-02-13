#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		map < ll, int > mapper;
		int me = 0, c = 0;
		for (int j = 0; j < m; j++) {
			ll a;
			cin >> a;
			if (mapper.count(a) && mapper[a] >= c) {
				me = max(me, j - c);
				c = mapper[a] + 1;
			}
			mapper[a] = j;
		}
		me = max(me, m - c);
		cout << me << endl;
	}
}
