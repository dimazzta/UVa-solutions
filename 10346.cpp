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
	int n, k; 
	while(cin >> n >> k){
		int ans = n;
		int b = 0;
		while(n){
			b += n;
			n = b / k;
			ans += b / k;
			b -= n * k;
		}
		cout << ans << endl;
	}
	return 0;
	
}

