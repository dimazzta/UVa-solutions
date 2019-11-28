#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


int to_dec(string cow) {
	int base = 4;
	int result = 0;
	int multi = 1;
	int n = cow.size();
	for (int i = n - 1; i >= 0; i--) {
		int num = 0;
		if (cow[i] == 'U') {
			num = 1;
		}
		else if (cow[i] == 'C') {
			num = 2;
		}
		else if (cow[i] == 'D') num = 3;
		result += multi * num;
		multi *= base;
	}
	return result;
}

string to_quad(int dec) {
	int base = 4;
	string result;
	while (dec) {
		int mod = dec % base;
		if (mod == 0) {
			result = 'V' + result;
		}
		else if (mod == 1) {
			result = 'U' + result;
		}
		else if (mod == 2) {
			result = 'C' + result;
		}
		else result = 'D' + result;
		dec /= base;
	}
	return result;
}


string pad(string a) {
	string result = a;
	assert(a.size() <= 8);
	for (int i = 0; i < 8 - a.size(); i++) {
		result = 'V' + result;
	}
	return result;
}

string add(string a, string b) {
	int a_dec = to_dec(pad(a));
	int b_dec = to_dec(pad(b));
	int result = a_dec + b_dec;
	return to_quad(result);
}

string shift_r(string a) {
	return 'V' + a.substr(0, a.size() - 1);
}

string shift_l(string a) {
	return a + 'V';
}


int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	cout << "COWCULATIONS OUTPUT" << endl;
	while (t--) {
		string a, b;
		cin >> a >> b;
		string result = b;
		for (int i = 0; i < 3; i++) {
			char o; cin >> o;
			if (o == 'A') {
				result = add(a, result);
			}
			else if (o == 'L') {
				result = shift_l(result);
			}
			else if (o == 'R') {
				result = shift_r(result);
			}
		}
		string out; cin >> out;
		if (pad(result) == out) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}


