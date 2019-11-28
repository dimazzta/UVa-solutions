#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 1e6;
bitset<nax> is_prime;
vll primes;

void sieve(){
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i < nax; i++){
		if (is_prime[i]){
			primes.push_back(i);
			for (ll j = (ll)i * i; j < nax; j += i){
				is_prime[j] = false;
			}
		}
	}
}

bool check(ll x){
	if (x < nax) {
		return is_prime[x];
	}
	
	for (int i = 0; i < primes.size(); i++){
		//if (primes[i] * primes[i] > x) break;
		if ((x % primes[i]) == 0){
			return false;
		}
	}
	return true;
}


int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	sieve();
	
	ll l, u;
	while(cin >> l >> u){
		int close = INT_MAX, far = -1;
		int prev_prime = -1;
		ii c = {-1, -1};
		ii d = {-1, -1};
		for (ll i = l; i <= u; i++){
			if (check(i)){
				if (prev_prime != -1){
					int dist = i - prev_prime;
					if (dist < close){
						close = dist;
						c = {prev_prime, i};
					}
					if (dist > far){
						far = dist;
						d = {prev_prime, i};
					}
				}
				prev_prime = i;
			}
		}
		if (c.first == -1){
			cout << "There are no adjacent primes." << endl;
		}
		else{
			cout << c.first << "," << c.second << " are closest, " << d.first << "," << d.second << " are most distant." << endl;
		}
	}
	return 0;
}


