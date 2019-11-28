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
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, m;
	while(cin >> n >> m, n || m){
		ll ans = 0;
		if (m > n) swap(n, m);
		ans = n * m * (m - 1);
		ans += m * n * (n - 1);
		
		for (ll i = 2; i < m; i++){
			ans += 4 * i * (i - 1);
		}
		
		for (ll i = 0; i < n - m + 1; i++){
			ans += 2 * m * (m - 1);
		}
	
		cout << ans << endl;
	}
	return 0;
}


