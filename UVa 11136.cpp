#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	while (scanf("%d", &n), n) {
		multiset<int> ms;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a;
			for (int j = 0; j < a; j++) {
				cin >> b;
				ms.insert(b);
			}
			auto itS = ms.begin(), itE = ms.end();
			sum += *--itE - *itS;
			ms.erase(itS); ms.erase(itE);
		}
		cout << sum << endl;
	}
}
