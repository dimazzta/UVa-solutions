#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	int n;
	while(cin >> n){
		vector<pair<ll, ll>> k;
		for (int i = n + 1; i <= 2 * n; i++){
			double y = double(n * i) / (i - n);
			if ((n * i) % (i - n) == 0){
				k.push_back({(n * i) / (i - n), i});
			}
		}
	
		cout << k.size() << endl;
		for (int i = 0; i < k.size(); i++){
			cout << "1/" << n << " = " << "1/" << k[i].first << " + " << "1/" << k[i].second << endl;
		}
		
	}
}
