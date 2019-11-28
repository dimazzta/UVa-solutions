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
                bs[j] = false;
            }
        }
    }
}

int numdiv(int x){
    int res = 1;
    int cur = 0;
    int n = primes.size();
    while(x > 1 && cur < n){
        int p = 1;
        while(x % primes[cur] == 0) {
            p++;
            x /= primes[cur];
        }
        cur++;
        res *= p;
    }
    if (x > 1) res *= 2;
    return res;
}



int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    sieve();
    int t;
    cin >> t;
    while(t--){
        int l, u; cin >> l >> u;
        int mx = -1;
        int n = -1;
        for (int i = l; i <= u; i++){
            int nd = numdiv(i);
            if (nd > mx){
                mx = nd;
                n = i;
            }
        }
        cout << "Between " << l << " and " << u << ", " << n << " has a maximum of " << mx << " divisors." << endl;
    }
	return 0;
}

