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
	//freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int d, v, u;
		cin >> d >> v >> u;
		if (v >= u || v == 0 || u == 0){
			cout << "Case " << tc << ": " << "can't determine" << endl;
		}
		else{
			double result = (double)d / (sqrt(u * u - v * v)) - (double)d / u;
			cout << setprecision(3) << fixed << "Case " << tc << ": " << result << endl;
		}
	}
	return 0;
}

