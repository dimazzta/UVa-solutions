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

const int nax = 1e6;
bitset<nax> bs;
vi primes;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < nax; i++){
        if (bs[i]){
            primes.push_back(i);
            for (ll j = (ll) i * i; j < nax; j += i){
                bs[j] = false;
            }
        }
    }
}

vi factorize(int x){
    int cur = 0;
    int n = primes.size();
    vi ans;
    while(x > 1 && cur < n){
        while(x % primes[cur] == 0) {
            x /= primes[cur];
            ans.push_back(primes[cur]);
        }
        cur++;
    }
    if (x > 1){
        ans.push_back(x);
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
    int x;
    while(cin >> x, x){
        cout << x << " = ";
        if (x < 0) {
            cout << "-1 x ";
            x *= -1;
        }
        vi f = factorize(x);
        bool r = false;
        for (int i = 0; i < f.size(); i++){
            if (r) cout << " x ";
            r = true;
            cout << f[i];
        }
        cout << endl;
    }
	return 0;
}

