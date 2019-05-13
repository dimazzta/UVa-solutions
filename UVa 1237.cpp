#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6 + 5;

class ST {
public:
	int *st, *lazy;
	map<int, string> stS, lazyS;

	ST() {
		st = new int[4 * maxN]; lazy = new int[4 * maxN];
		memset(st, 0, 4 * maxN * sizeof(*st));
		memset(lazy, 0, 4 * maxN * sizeof(*lazy));
		stS.clear(); lazyS.clear();
	}

	int left(int p)
	{
		return (p << 1);
	}
	int right(int p) {
		return (p << 1) + 1;
	}

	void update(int p, int L, int R, int UL, int UR, string & car) {
		if (lazy[p]) {
			st[p] += lazy[p];
			stS[p] = lazyS[p];
			lazy[left(p)] += lazy[p]; lazyS[left(p)] = lazyS[p];
			lazy[right(p)] += lazy[p]; lazyS[right(p)] = lazyS[p];


			lazy[p] = 0;
			lazyS[p] = "";
		}
		if (R < UL || L > UR) return;
		if (L >= UL && R <= UR) {
			st[p]++; stS[p] = car;
			lazy[left(p)]++; lazyS[left(p)] = car;
			lazy[right(p)]++; lazyS[right(p)] = car;
			return;
		}
		update(left(p), L, (L + R) / 2, UL, UR, car);
		update(right(p), (L + R) / 2 + 1, R, UL, UR, car);
	}

	string q(int p, int L, int R, int idx) {
		if (L > idx || R < idx) return "";
		if (lazy[p]) {
			st[p] += lazy[p];
			stS[p] = lazyS[p];
			lazy[left(p)] += lazy[p]; lazyS[left(p)] = lazyS[p];
			lazy[right(p)] += lazy[p]; lazyS[right(p)] = lazyS[p];
			lazy[p] = 0;
			lazyS[p] = "";
		}

		if (L == R) {
			if (st[p] == 1) {
				return stS[p];
			}
			else return "";
		}
		return q(left(p), L, (L + R) / 2, idx) + q(right(p), (L + R) / 2 + 1, R, idx);
	}

};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int d; cin >> d;
		ST st;
		for (int i = 0; i < d; i++) {
			string s; int l, h;
			cin >> s >> l >> h;
			st.update(1, 1, maxN, l, h, s);
		}
		int q; cin >> q;
		for (int i = 0; i < q; i++) {
			int qr;
			cin >> qr;
			string ans = st.q(1, 1, maxN, qr);
			if (ans == "") {
				cout << "UNDETERMINED" << endl;
			}
			else {
				cout << ans << endl;
			}
		}
		if (t != 0) cout << endl;
	}
}
