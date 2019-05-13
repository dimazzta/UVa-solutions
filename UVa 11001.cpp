#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	int V, v;
	while (cin >> V >> v){
		if (V == 0) break;
		double mc = 0; int d = 0;
		for (int i = 1; ; ++i){
			double nv = double(V) / i;
			if (nv <= v) break;
			double n_max = double(0.3) * sqrt(nv - v) * i;
			if (fabs(n_max - mc) < 1e-9){
				d = 0; break;
			}
			if (n_max >= mc){
				mc = n_max;
				d = i;
			}
		}
		cout << d << endl;
	}
}
