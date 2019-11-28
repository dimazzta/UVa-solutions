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

ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

const int nax = 1e6 + 5;
vi spf(nax);

void sieve(){
    for (int i = 0; i < nax; i++) spf[i] = i;
    for (int i = 2; i < nax; i++){
        if (spf[i] == i){
            for (ll j = (ll)i * i; j < nax; j += i){
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

map<int, int> factorize(int x){
    map<int, int> ans;
    while(x > 1){
        ans[spf[x]]++;
        x /= spf[x];
    }
    return ans;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll l = 1;
//    for (ll i = 2; i <= 25; i++){
//        l = lcm(l, i);
//        cout << l << endl;
//    }

    sieve();
    vi dp(nax);
    map<int, int> current;
    dp[1] = 1;
    for (int i = 2; i < nax; i++){
        dp[i] = dp[i - 1];
        map<int, int> mp = factorize(i);
        for (auto kvp : mp){
            if (current[kvp.first] < kvp.second){
                dp[i] *= pow(kvp.first, kvp.second - current[kvp.first]);
                current[kvp.first] = kvp.second;
            }
        }
        while(dp[i] % 10 == 0){
            dp[i] /= 10;
        }
        dp[i] = dp[i] % 100;
    }
    int w;
    while(cin >> w, w) cout << dp[w] % 10 << endl;
	return 0;
}

