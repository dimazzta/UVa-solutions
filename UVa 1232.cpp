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



class ST {
private:
	vii st, lazy;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void updateMin(int p, int L, int R, int UL, int UR, int val) {
		if (L > UR - 1 || R < UL) return; // -1 means the range we are updating is shorter by e.g 4..4 stores actual 4..5 value
		if (L >= UL && R <= UR - 1) {
			st[p].first = max({ st[p].first, val, lazy[p].first }); // min for range is maximum between already stored value, current building height and pending parent update height
			if (L != R) {
				lazy[left(p)].first = max(lazy[left(p)].first, val);
				lazy[right(p)].first = max(lazy[right(p)].first, val);
			}
			return; // do not recur to children
		}
		updateMin(left(p), L, (L + R) / 2, UL, UR, val);
		updateMin(right(p), (L + R) / 2 + 1, R, UL, UR, val);
		st[p].first = min(st[left(p)].first, st[right(p)].first); 
	}
	void updateMax(int p, int L, int R, int UL, int UR, int val) {
		if (L > UR - 1 || R < UL) return; 
		if (L >= UL && R <= UR - 1) {
			st[p].second = max({ st[p].second, val, lazy[p].second });
			if (L != R) {
				lazy[left(p)].second = max(lazy[left(p)].second, val);
				lazy[right(p)].second = max(lazy[right(p)].second, val);
			}
			return; 
		}
		updateMax(left(p), L, (L + R) / 2, UL, UR, val);
		updateMax(right(p), (L + R) / 2 + 1, R, UL, UR, val);
		st[p].second = max(st[left(p)].second, st[right(p)].second);
	}

	int overlap(int p, int L, int R, int UL, int UR, int val) {
		st[p].first = max(st[p].first, lazy[p].first);
		if (L != R) {
			lazy[left(p)].first = max(lazy[left(p)].first, lazy[p].first);
			lazy[right(p)].first = max(lazy[right(p)].first, lazy[p].first);
		}
		lazy[p].first = 0;

		st[p].second = max(st[p].second, lazy[p].second);
		if (L != R) {
			lazy[left(p)].second = max(lazy[left(p)].second, lazy[p].second);
			lazy[right(p)].second = max(lazy[right(p)].second, lazy[p].second);
		}
		lazy[p].second = 0;

		if (L > UR - 1 || R < UL) return 0;
		if (L >= UL && R <= UR - 1) {
			if (val < st[p].first) return 0;
			if (val >= st[p].second) return R - L + 1;
		}
		if (L == R) return 0;

		int l = overlap(left(p), L, (L + R) / 2, UL, UR, val);
		int r = overlap(right(p), (L + R) / 2 + 1, R, UL, UR, val);
		return l + r;
	}
public:
	ST(int n) {
		st.assign(4 * n, { 0, 0 });
		lazy.assign(4 * n, { 0, 0 });
		this->n = n;
	}
	void update(int L, int R, int height) {
		updateMin(1, 0, n - 1, L, R, height);
		updateMax(1, 0, n - 1, L, R, height);
	}
	int overlap(int L, int R, int height) {
		return overlap(1, 0, n - 1, L, R, height);
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ST st(1e5 + 5);
		ll ovl = 0;
		for (int i = 0; i < n; i++) {
			int l, r, h;
			cin >> l >> r >> h;
			ovl += st.overlap(l, r, h);
			st.update(l, r, h);
		}
		cout << ovl << endl;
	}
}
