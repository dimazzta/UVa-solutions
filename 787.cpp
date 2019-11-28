#include <bits/stdc++.h>
using namespace std;
#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;


struct bigint {
	vi num;
	int size;
	int sign;
	bigint() {
		size = 0;
		sign = 1;
	}
	bigint(long long a) {
		
		if (a < 0) {
			sign = -1;
		}
		else if (a > 0) {
			sign = 1;
		}
		else {
			sign = 0;
			size = 1;
			return;
		}
		while (a) {
			num.push_back(abs(a) % 10);
			a /= 10;
		}
		size = num.size();
	}
	bigint(bigint & b) {
		size = b.size;
		sign = b.sign;
		num.assign(size, 0);
		for (int i = 0; i < size; i++) {
			num[i] = b.num[i];
		}
	}
	string t_str() {
		string res;
		if (sign == 0) return "0";
		if (sign < 0) res = "-";
		for (int i = size - 1; i >= 0; i--) {
			res += num[i] + '0';
		}
		return res;
	}
};

bigint mult(bigint & a, bigint & b) {
	bigint c;
	c.sign = a.sign * b.sign;
	if (c.sign == 0) {
		return c;
	}
	c.size = a.size + b.size - 1;
	c.num.assign(c.size, 0);

	for (int i = 0; i < a.size; i++) {
		int f = 0;
		for (int j = 0; j < b.size; j++) {
			int sum = c.num[i + j] + f + (a.num[i] * b.num[j]);
			c.num[i + j] = sum % 10;
			f = sum / 10;
		}
		if (f) {
			if (i + b.size < c.size) {
				c.num[i + b.size] = f;
			}
			else {
				c.size++;
				c.num.push_back(f);
			}
		}
	}
	return c;
}

int compare(bigint & a, bigint & b) {
	if (a.sign < b.sign) {
		return -1;
	}
	if (a.sign > b.sign) {
		return 1;
	}
	if (a.sign == b.sign) {
		if (a.sign == 0) {
			return 0;
		}
		int result = 0;
		if (a.size > b.size) {
			result = 1;
		}
		if (a.size < b.size) {
			result = -1;
		}
		if (a.size == b.size) {
			for (int i = a.size - 1; i >= 0; i--) {
				if (a.num[i] > b.num[i]) {
					result = 1;
					break;
				}
				if (a.num[i] < b.num[i]) {
					result = -1;
					break;
				}
			}
		}
		return result * a.sign;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef DEBUG
	freopen("out.txt", "w", stdout);
#endif
	vi a;
	int x;
	while (cin >> x) {
		if (x != -999999) {
			a.push_back(x);
			continue;
		}

		bigint mx(-LLONG_MAX);
		for (int i = 0; i < a.size(); i++) {
			bigint prod(1LL);
			for (int j = i; j < a.size(); j++) {
				bigint temp(a[j]);
				prod = mult(prod, temp);
				if (compare(mx, prod) == -1) {
					mx = bigint(prod);
				}
			}
		}
		cout << mx.t_str() << endl;


		a.clear();
	}


	system("pause");
}

