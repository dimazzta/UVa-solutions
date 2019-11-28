#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 2e7 + 5;
bitset<nax> bs;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < nax; i++){
		if (bs[i]){
			for (ll j = (ll)i * i; j < nax; j+=i){
				bs[j] = 0;
			}
		}
	}
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	sieve();
	vii ans;
	for (int i = 3; i < nax - 2; i++){
		if (bs[i] && bs[i + 2]){
			ans.push_back({i, i + 2});
		}
	}

	int n;
	while(cin >> n){
		n--;
		cout << "(" << ans[n].first << ", " << ans[n].second << ")" << endl; 
	}
	return 0;
}


