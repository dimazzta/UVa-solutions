#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 1e5;
bitset<nax> bs;
vi primes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < nax; i++){
        if (bs[i]){
            primes.push_back(i);
            for (ll j = (ll)i * i; j < nax; j += i){
                bs[j] = 0;
            }
        }
    }
}

int phi(int x){
    int cur = 0;
    int ans = x;
    int n = primes.size();
    while(x > 1 && cur < n){
        if (x % primes[cur] == 0){
            ans -= ans / primes[cur];
            while(x % primes[cur] == 0) x /= primes[cur];
        }
        cur++;
    }
    if (x > 1){
        ans -= ans / x;
    }
    return ans;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    sieve();
    int n;
    while(cin >> n, n){
        cout << phi(n) << endl;
    }
	return 0;
}

