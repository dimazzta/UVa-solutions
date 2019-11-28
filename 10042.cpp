#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 1e5;
vi primes;
int spf[nax + 5];

void sieve() {
	spf[0] = spf[1] = 0;
	for (int i = 2; i < nax; i++) spf[i] = i;

	for (int i = 2; i < nax; i++) {
		if (spf[i] == i) {
			primes.push_back(i);
			for (ll j = (ll)i * i; j < nax; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}

vi factorize(int n) {
	vi f;
	int idx = 0;
	while (n != 1 && idx < primes.size()) {
		if (n % primes[idx] == 0) {
			f.push_back(primes[idx]);
			n /= primes[idx];
		}
		else {
			idx++;
		}
	}
	if (n != 1) f.push_back(n);
	return f;
}


int sum_of_digits(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sieve();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		while (true) {
			n++;
			int sum_of_n = sum_of_digits(n);
			vi fact = factorize(n);
			if (fact.size() == 1) continue;
			int sum_of_fact = 0;
			for (int i = 0; i < fact.size(); i++) {
				sum_of_fact += sum_of_digits(fact[i]);
			}
			if (sum_of_n == sum_of_fact) {
				cout << n << endl;
				break;
			}
		}
	}
	return 0;
}


