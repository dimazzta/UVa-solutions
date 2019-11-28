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
	freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int i = 0; i < t; i++){
		int n; cin >> n;
		if (n == 1){
			cout << setprecision(3) << fixed << 0.000 << endl;
		}
		else if (n == 2){
			cout << setprecision(3) << fixed << 4.000 << endl;
		}
		else{
			int cnt = (n - 2) * (n - 2);
			double result = cnt * sqrt(2) + (n * n - cnt);
			cout << setprecision(3) << fixed << result << endl;
		}
		if (i != t - 1) cout << endl;
	}

	return 0;
}

