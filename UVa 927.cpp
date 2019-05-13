#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int calcN(ll a0, ll d, ll s){
	double D = sqrt((2 * a0 - d) * (2 * a0 - d) + 8 * d * s);
	double x1 = double(-1 * (2 * a0 - d) + D) / (2 * d);
	double x2 = double(-1 * (2 * a0 - d) - D) / (2 * d);
	if (x1 > 0) return ceil(x1);
	else return ceil(x2);
}

int main(){
	int c;
	cin >> c;
	for (int test = 0; test < c; test++){
		vector<int> C(21);
		int b = 0;
		int p;
		cin >> p;
		for (int i = 0; i < p + 1; i++) cin >> C[i];
		int d, k;
		cin >> d;
		cin >> k;
		int n = calcN(d,d,k);
		ll ans = 0;
		for (int i = 0; i < p + 1; i++) {
			ans += C[i] * pow(n, i);
		}
		cout << ans << endl;
	}
}
