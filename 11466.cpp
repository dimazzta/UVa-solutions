#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 4e7;
bitset<nax> bs;
vll primes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < nax; i++){
        if (bs[i]){
             primes.push_back(i);
             for (ll j = (ll) i * i; j < nax; j += i){
                bs[j] = 0;
             }
        }
    }
}

ll lpd(ll x){
    if (x < nax){
        if (bs[x]) return -1;
    }
    ll mx = -1;
    int n = primes.size();
    int cur = 0;
    int cnt = 0;

    while(x > 1 && cur < n){
        if (x % primes[cur] == 0){
            mx = primes[cur];
            cnt++;
        }
        while(x % primes[cur] == 0){
            x /= primes[cur];
        }
        cur++;
    }

    if (mx == -1) return mx;
    if (x > 1){
        mx = max(mx, x);
        cnt++;
    }
    if (cnt <= 1) return -1;
    return mx;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    sieve();
    ll x;
    while(cin >> x, x) {
        cout << lpd(abs(x)) << endl;
    }
	return 0;
}

