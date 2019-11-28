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

	int N, M, c;
	while(cin >> N >> M >> c, N || M || c){
		
		int n, m;
		n = N - 7;
		m = M - 7;
		ll ans = 0;
		if (c == 1){
			ans = (ll)(ceil(n / 2.0) * ceil(m / 2.0) + floor(n / 2.0) * floor(m / 2.0));
		}
		else{
			ans = (ll)(ceil(n / 2.0) * floor(m / 2.0) + floor(n / 2.0) * ceil(m / 2.0));
		}
		cout << ans << endl;
		
	}
	return 0;
}


