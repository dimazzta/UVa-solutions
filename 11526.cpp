#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;



long long H(int n){
	if (n <= 0)
        return 0;
	long long res = 0;
	ll p = -1;
	for(int i = 1; i <= sqrt(n); i++){
		ll cnt = n / i;
		res += cnt;
		if (p != -1){
			res += (p - cnt) * (i - 1);
		}
		p = cnt;
	}
	//res += (int)sqrt(n) * (p - (int)sqrt(n));
	return res;
}


int main(){
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << H(n) << endl;
	}
	return 0;
}


