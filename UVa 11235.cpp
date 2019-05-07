#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;
typedef tuple<int, int, int> iii;
typedef vector<long long> vll;

const int maxN = 1e5;
vi st;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

void update(int p, int L, int R, int I, int val) {
	if (L > I || R < I) return;
	if (L == R) {
		st[p] = max(val, st[p]);
		return;
	}
	update(left(p), L, (L + R) / 2, I, val);
	update(right(p),  (L + R) / 2 + 1, R, I, val);
	st[p] = max(st[left(p)], st[right(p)]);
}

int rmq(int p, int L, int R, int UL, int UR) {
	if (L > UR || R < UL || UL > UR) return 0;
	if (L >= UL && R <= UR) {
		return st[p];
	}
	return max(rmq(left(p), L, (L + R) / 2, UL, UR), rmq(right(p), (L + R) / 2 + 1, R, UL, UR));
}

void init(int n) {
	st.assign(4 * n, 0);
}


int main() {

	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		int q; cin >> q;
		vi a(n + 2), freq(n + 2);
		map<int, int> left, right;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int prev = a[1];
		int start = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i] != prev) {
				for (int j = start; j < i; j++) freq[j] = i - start;
				left[prev] = start; right[prev] = i - 1;
				start = i;
			}
			prev = a[i];
		}
		for (int j = start; j <= n; j++) freq[j] = n - start + 1;
		left[prev] = start; right[prev] = n;

		init(n);
		for (int i = 1; i <= n; i++) {
			update(1, 1, n, i, freq[i]);
		}

		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			if (a[l] == a[r]) {
				cout << r - l + 1 << endl;
			}
			else if ((l == 1 || a[l] != a[l - 1]) && (r == n || a[r + 1] != a[r])) {
				cout << rmq(1, 1, n, l, r) << endl;
			}
			else if ((l == 1 || a[l] == a[l - 1]) && (r == n || a[r + 1] != a[r])) {
				int full_q = rmq(1, 1, n, right[a[l]] + 1, r);
				int part_q = right[a[l]] - l + 1;
				cout << max(part_q, full_q) << endl;
			}
			else if ((l == 1 || a[l] != a[l - 1]) && (r == n || a[r + 1] == a[r])) {
				int full_q = rmq(1, 1, n, l, left[a[r]] - 1);
				int part_q = r - left[a[r]] + 1;
				cout << max(part_q, full_q) << endl;
			}
			else {
				int part_q1 = r - left[a[r]] + 1;
				int part_q2 = right[a[l]] - l + 1;;
				int full_q = rmq(1, 1, n, right[a[l]] + 1, left[a[r]] - 1);
				cout << max({ full_q, part_q2, part_q1 }) << endl;
			}
		}

	}
	
}
