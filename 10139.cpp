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

vii factorize(int x){
    int cur = 0;
    int n = primes.size();
    vii ans;
    while(x > 1 && cur < n){
        if (x % primes[cur] == 0) {
            ans.push_back({primes[cur], 0});
            while(x % primes[cur] == 0) {
                ans.back().second++;
                x /= primes[cur];
            }

        }
        cur++;
    }
    if (x > 1){
        ans.push_back({x, 1});
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
    int n, m;
    while(cin >> n >> m){
        vii f = factorize(m);
        bool can = true;
        for (int i = 0; i < f.size(); i++){
            int cnt = 0;
            for (ll k = f[i].first; k <= n; k *= f[i].first){
                cnt += n / k;
            }
            if (cnt < f[i].second){
                can = false;
                break;
            }
        }
        if (can){
            cout << m << " divides " << n << "!" << endl;
        }
        else{
            cout << m << " does not divide " << n << "!" << endl;
        }
    }

	return 0;
}

