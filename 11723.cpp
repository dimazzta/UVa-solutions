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
	int r, n;
	int tc = 1;
	while(cin >> r >> n, r || n){
		if (r <= n) cout << "Case " << tc++ << ": " << 0 << endl;
		else{
			int cnt =  ceil((double)(r - n) / n);
			if (cnt > 26){
				cout << "Case " << tc++ << ": " << "impossible" << endl;
				
			}
			else {
				cout << "Case " << tc++ << ": " << cnt << endl;
			}
		}
	}
	return 0;
}

