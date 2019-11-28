#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p[] = {60, 300, 1500, 15000};
	int mo[] = {10, 100, 1000, 10000};
	int t; cin >> t;
	while(t--){
		int a, b, n, m; cin >> a >> b >> n >> m;
		vi period(p[m - 1] + 1);
		period[0] = a % mo[m - 1];
		period[1] = b % mo[m - 1];
		for (int i = 2; i <= p[m - 1]; i++){
			period[i] = (period[i - 1] + period[i - 2]) % mo[m - 1];
		}
		int ans = period[n % p[m - 1]];
		cout << ans << endl;
	}
	return 0;
}


