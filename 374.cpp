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


ll binexp(ll base, ll pow, ll mod){
    ll cur = base;
    ll ans = 1;
    while(pow){
        if (pow % 2 == 1){
            ans *= cur;
            ans %= mod;
        }
        cur *= cur;
        cur %= mod;
        pow >>= 1;
    }
    return ans;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll b, p, m;
    while(cin >> b >> p >> m){
        cout << binexp(b, p, m) << endl;
    }
	return 0;
}

