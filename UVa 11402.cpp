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
const int maxN = 1024005;

class ST {
private:
	int left(int p) { return (p << 1); }
	int right(int p) { return (p << 1) + 1; }
	int n;
	// lazy: 0 - empty 1 - clear, 2 - set, 3 - flip
	vector<int> st, lazy;
	void updateLazyChildren(int p, int way, int L, int R) {
		if (way == 1) {
			st[p] = 0;
			if (L != R) {
				lazy[left(p)] = 1;
				lazy[right(p)] = 1;
			}
		}
		if (way == 2) {
			st[p] = R - L + 1;
			if (L != R) {
				lazy[left(p)] = 2;
				lazy[right(p)] = 2;
			}

		}
		if (way == 3) {
			st[p] = R - L + 1 - st[p];
			if (L != R) {
				if (lazy[left(p)] == 1) {
					lazy[left(p)] = 2;
				}
				else if (lazy[left(p)] == 2) {
					lazy[left(p)] = 1;
				}
				else if (lazy[left(p)] == 3) {
					lazy[left(p)] = 0;
				}
				else {
					lazy[left(p)] = 3;
				}


				if (lazy[right(p)] == 1) {
					lazy[right(p)] = 2;
				}
				else if (lazy[right(p)] == 2) {
					lazy[right(p)] = 1;
				}
				else if (lazy[right(p)] == 3) {
					lazy[right(p)] = 0;
				}
				else {
					lazy[right(p)] = 3;
				}
			}
		}
	}

	void update(int p, int L, int R, int UL, int UR, int way) {
		if (lazy[p]) {
			updateLazyChildren(p, lazy[p], L, R);
			lazy[p] = 0;
		}
		if (L > UR || R < UL) return;
		if (L >= UL && R <= UR) {
			updateLazyChildren(p, way, L, R);
			return;
		}
		update(left(p), L, (L + R) / 2, UL, UR, way);
		update(right(p), (L + R) / 2 + 1, R, UL, UR, way);
		st[p] = st[left(p)] + st[right(p)];
	}
	int rsq(int p, int L, int R, int UL, int UR) {
		if (L > UR || R < UL) return 0;
		if (lazy[p]) {
			updateLazyChildren(p, lazy[p], L, R);
			lazy[p] = 0;
		}
		if (L >= UL && R <= UR) {
			return st[p];
		}

		int l = rsq(left(p), L, (L + R) / 2, UL, UR);
		int r = rsq(right(p), (L + R) / 2 + 1, R, UL, UR);
		return l + r;
	}

	void build(int p, int L, int R, char * values) {
		if (L == R) {
			st[p] = values[L] == '0' ? 0 : 1;
		}
		else {
			build(left(p), L, (L + R) / 2, values);
			build(right(p), (L + R) / 2 + 1, R, values);
			st[p] = st[left(p)] + st[right(p)];
		}
	}

public:
	ST(int n) {
		this->n = n;
		st.assign(4 * n, 0); lazy.assign(4 * n, 0);
	}
	void update(int L, int R, int way) {
		update(1, 0, n - 1, L, R, way);
	}
	int rsq(int L, int R) {
		return rsq(1, 0, n - 1, L, R);
	}
	void build(char * values) {
		build(1, 0, n - 1, values);
	}
};



int main() {

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		printf("Case %d:\n", test);
		int m;
		cin >> m;
		int n = 0;
		char s[maxN];
		for (int j = 0; j < m; j++) {
			int repeat; char needle[51];
			cin >> repeat; cin >> needle;
			int len = strlen(needle);
			for (int r = 0; r < repeat; r++) {
				for (int b = 0; b < len; b++) {
					s[n++] = needle[b];
				}
			}
		}
		ST st(n);
		st.build(s);
		int q;
		cin >> q;
		int qN = 1;
		for (int i = 0; i < q; i++) {
			char type; int a, b;
			cin >> type >> a >> b;
			if (type == 'F') {
				st.update(a, b, 2);
			}
			if (type == 'E') {
				st.update(a, b, 1);
			}
			if (type == 'I') {
				st.update(a, b, 3);
			}
			if (type == 'S') {
				int ans = st.rsq(a, b);
				printf("Q%d: %d\n", qN++, ans);
			}
		}
	}
	
}
