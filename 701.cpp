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
	//freopen("out.txt", "w", stdout);
	int n;
	while(cin >> n){
		ll x = floor(log10(n)) + 2;
		while(true){
			double l = log2(n) + x * log2(10);
			double r = log2(n + 1) + x * log2(10);	
			if (abs(floor(r) - ceil(l)) <= 1e-9){
				ll e = (ll)(floor(r));
				cout << e << endl;
				break;
			}
			x++;
		}
	}
	return 0;
}


