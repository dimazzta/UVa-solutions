#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m), n || m) {
		int rN = n, rM = m;
		if (n > m) {
			n = m + n;
			m = n - m;
			n = n - m;
		}
		if (n == 1) {
			cout << m << " knights may be placed on a " << rN << " row " << rM << " column board." << endl;
		}
		else if (n == 2) {
			int cnt = 0;
			int rate = m / 2;
			if (rate % 2 != 0) {
				cnt = 4 * (rate / 2 + 1);
			}
			else {
				cnt = (4 * rate / 2) + (m % 2) * 2;
			}
			cout << cnt << " knights may be placed on a " << rN << " row " << rM << " column board." << endl;
		}
		else {
			int cnt = ceil(((double)m / 2)) * ceil((double)n / 2) + floor(((double)m / 2)) * floor((double)n / 2);
			cout << cnt << " knights may be placed on a " << rN << " row " << rM << " column board." << endl;
		}
	}
	
}

