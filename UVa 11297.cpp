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


int left(int p) {
	return (p << 1);
}
int right(int p) {
	return (p << 1) + 1;
}

class Node {
public:
	vii st; int n;
	void update(int p, int L, int R, int idx, int value) {
		if (R < idx || L > idx) return;
		if (L == R) {
			st[p].first = value; st[p].second = value;
			return;
		}
		update(left(p), L, (L + R) / 2, idx, value);
		update(right(p), (L + R) / 2 + 1, R, idx, value);
		st[p].first = min(st[left(p)].first, st[right(p)].first);
		st[p].second = max(st[left(p)].second, st[right(p)].second);
	}
	int maxQ(int p, int L, int R, int UL, int UR) {
		if (L > UR || R < UL) return 0;
		if (L >= UL && R <= UR) {
			return st[p].second;
		}
		int l = maxQ(left(p), L, (L + R) / 2, UL, UR);
		int r = maxQ(right(p), (L + R) / 2 + 1, R, UL, UR);
		return max(l, r);
	}

	int minQ(int p, int L, int R, int UL, int UR) {
		if (L > UR || R < UL) return INT_MAX;
		if (L >= UL && R <= UR) {
			return st[p].first;
		}
		int l = minQ(left(p), L, (L + R) / 2, UL, UR);
		int r = minQ(right(p), (L + R) / 2 + 1, R, UL, UR);
		return min(l, r);
	}
	Node(int n) {
		st.assign(4 * n, { 0, 0 });
	}
};



class ST {
public:
	vector<Node> st; int n;
	ST(int n) {
		this->n = n;
		st.assign(4 * n, Node(n));
	}
	void update(int p, int L, int R, int x, int y, int value) {
		if (L > x || R < x) return;
		if (L == R) {
			st[p].update(1, 1, n, y, value);
			return;
		}
		update(left(p), L, (L + R) / 2, x, y, value);
		update(right(p), (L + R) / 2 + 1, R, x, y, value);
		for (int i = 0; i < st[p].st.size(); i++) {
			st[p].st[i].first = min({ st[left(p)].st[i].first, st[right(p)].st[i].first });
			st[p].st[i].second = max({ st[left(p)].st[i].second, st[right(p)].st[i].second });
		}
	}
	int minQ(int p, int L, int R, int UL, int UR, int ul, int ur) {
		if (L > UR || R < UL) return INT_MAX;
		if (L >= UL && R <= UR) {
			return st[p].minQ(1, 1, n, ul, ur);
		}
		int l = minQ(left(p), L, (L + R) / 2, UL, UR, ul, ur);
		int r = minQ(right(p), (L + R) / 2 + 1, R, UL, UR, ul, ur);
		return min(l, r);
	}

	int maxQ(int p, int L, int R, int UL, int UR, int ul, int ur) {
		if (L > UR || R < UL) return 0;
		if (L >= UL && R <= UR) {
			return st[p].maxQ(1, 1, n, ul, ur);
		}
		int l = maxQ(left(p), L, (L + R) / 2, UL, UR, ul, ur);
		int r = maxQ(right(p), (L + R) / 2 + 1, R, UL, UR, ul, ur);
		return max(l, r);
	}
};

int main() {
	int n, q;
	cin >> n;
	ST tree(n + 5);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int  value;
			cin >> value;
			tree.update(1, 1, n, i, j, value);
		}
	}
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		char t;
		cin >> t;
		if (t == 'q') {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			int mn = tree.minQ(1, 1, n, x1, x2, y1, y2);
			int mx = tree.maxQ(1, 1, n, x1, x2, y1, y2);
			cout << mx << " " << mn << endl;
 		}
		if (t == 'c') {
			int x, y, value;
			cin >> x >> y >> value;
			tree.update(1, 1, n, x, y, value);
		}
	}

}
