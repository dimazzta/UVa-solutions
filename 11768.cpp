#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int x, y, d;

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

void ee(int a, int b) {
	if (b == 0) { 
		x = 1; 
		y = 0; 
		d = a; 
		return; 
	}
	ee(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double _x1, _y1, _x2, _y2; cin >> _x1 >> _y1 >> _x2 >> _y2;
		int x1 = _x1 * 10, x2 = _x2 * 10, y1 = _y1 * 10, y2 = _y2 * 10;
		
		int a = y2 - y1;
		int b = x1 - x2;
		int c = x1 * y2 - x2 * y1;
		if (c % gcd(a, b) != 0){
			cout << 0 << endl;
		}
		else{
			ee(a, b);
			int rate = c / d;
		}
	}

	return 0;
}


