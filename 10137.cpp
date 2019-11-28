#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//freopen("out.txt", "w", stdout);
	int n;
	while (scanf("%d", &n), n) {
		vector<int> a(n);
		int sa = 0;
		for (int i = 0; i < n; i++) {
			//double x; cin >> x;
			int dollar, cent;
            scanf("%d.%d", &dollar, &cent);
			int ro = dollar * 100 + cent;
			a[i] = ro;
			sa += ro;
		}

		int l = sa / n;
		int h = ceil((double)sa / n);

		int dif = 0;
		int ndif = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] < l) {
				dif += l - a[i];
			}
			if (a[i] > h)
				ndif += a[i] - h;
		}
		int res = max(dif, ndif);
		printf("$%d.", res / 100);
        if (res % 100 < 10)
            printf("0");
        printf("%d\n", res % 100);

	}
	return 0;
}




