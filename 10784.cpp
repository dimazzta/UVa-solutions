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
	
	ll N;
	int tc = 1;
	while(cin >> N, N){
		ll n = ceil((3.0 + sqrt(9 + 8 * N)) / 2.0);
		cout << "Case " << tc++ << ": " << n << endl;
	}
	return 0;
}


