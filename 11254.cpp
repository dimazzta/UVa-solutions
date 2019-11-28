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
	ll n;
	while(cin >> n, n > 0){
		int mx = 1;
		int ans_l = 0, ans_r = 0;
		for (ll r = 1; r * r < 2 * n; r++){
			double l = (double)(2 * n - r * r + r) / (2 * r);
			if (ceil(l) == l){
				ans_l = l;
				ans_r = r;
			}
		}
		cout << n << " = ";
		cout << ans_l << " + ... + " << ans_l + ans_r - 1 << endl;
		
	}
	return 0;
}

