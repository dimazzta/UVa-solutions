#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


vi get_divisors(int x) {
	vi ans;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ans.push_back(i);
			if (x / i != i) ans.push_back(x / i);
		}
	}
	return ans;
}
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}



int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		vi div = get_divisors(n);
		int cnt = 0;
		for (int i = 0; i < div.size(); i++) {
			for (int j = i; j < div.size(); j++) {
				if (lcm(div[i], div[j]) == n) {
					cnt++;
				}
			}
		}
		cout << n << " " << cnt << endl;
	}
	return 0;
}


