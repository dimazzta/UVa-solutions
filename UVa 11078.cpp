#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int mx = -INT_MAX;
		int cmax;
		cin >> cmax;
		for (int i = 1; i < n; i++){
			int a; cin >> a;
			mx = max(mx, cmax - a);
			cmax = max(cmax, a);
		}
		cout << mx << endl;
	}
}
