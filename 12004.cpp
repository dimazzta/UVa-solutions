#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 1e5 + 5;
ll a[nax];

int main(){
	a[1] = 0;
	for (ll i = 2; i < nax; i++){
		a[i] = a[i - 1] + i - 1;
	}
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n; cin >> n;
		if (n == 1) cout << "Case " << tc << ": " << 0 << endl;
		else if (a[n] % 2 == 0){
			cout << "Case " << tc << ": " << a[n] / 2 << endl;
		}
		else{
			cout << "Case " << tc << ": " << a[n] << "/2" << endl;
		}
	}
	
	return 0;
}

