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

const int nax = 2e6 + 5;

vi phi(nax);
vi dphi(nax);

void sieve(){
    phi[1] = 1;
    for (int i = 1; i < nax; i++) phi[i] = i;
    for(int i = 2; i < nax; i++){
        if (phi[i] == i){
            for (int j = i; j < nax; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }

    for (int i = 2; i < nax; i++){
        int d = 0;
        int v = i;
        while(v > 1){
            v = phi[v];
            d++;
        }
        dphi[i] = d;
    }
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    sieve();
    vll pref(nax);
    for (int i = 2; i < nax; i++){
        pref[i] = pref[i - 1] + dphi[i];
    }

    int t; cin >> t;

    while(t--){
        int l, r; cin >> l >> r;
        int res = pref[r] - pref[l - 1];
        cout << res << endl;
    }
	return 0;
}

