#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


ll expmod(ll a, ll pow, int mod){
	if (pow == 0) return 1;
	ll ans = 1;
	ll base = a;
	while(pow){
		if (pow % 2){
			ans = (ans * base) % mod; 
		}
		base = (base * base) % mod;
		pow /= 2;
	}
	return ans;
}

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; 
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int mod, n, k;
		cin >> n >> k >> mod;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			ans += x;
		}
		ll exp = expmod(n, k - 1, mod);
		exp = (k * exp) % mod;
		exp = (exp * ans) % mod;
		cout << "Case " << tc << ": " << exp << endl;
		
	}
	return 0;
}


