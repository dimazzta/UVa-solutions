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
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n; cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (i == n / 2) ans = x;
		}
		cout << "Case " << tc << ": " << ans << endl; 
	}
	return 0;
}

