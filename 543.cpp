#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 1e6 + 5;
vi primes;
bitset<nax> is_prime;

void sieve(){
	is_prime.set();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < nax; i++){
		if (is_prime[i]){
			for (ll j = (ll)i * i; j < nax; j += i){
				is_prime[j] = false;
			}
			primes.push_back(i);
		}
	}
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sieve();
	int n;
	while(cin >> n, n){
		for (int i = 0; i < primes.size(); i++){
			if (is_prime[n - primes[i]]){
				cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;
				break;
			}
		}
	}
	return 0;
}


