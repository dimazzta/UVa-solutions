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

const int nax = 1e7 + 5;
vi spf(nax);
void sieve(){
    for (int i  = 0; i < nax; i++) spf[i] = i;
    for (int i = 2; i < nax; i++){
        if (spf[i] == i){
            for(ll j = (ll) i * i; j < nax; j += i){
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

    sieve();
    int t; cin >> t;
    while(t--){
        int a, c; cin >> a >> c;
        if (c % a != 0){
            cout << "NO SOLUTION" << endl;
            continue;
        }

        map<int, int> fa = factorize(a);
        map<int, int> fc = factorize(c);

        int b = 1;
        bool can = true;
        for (auto kvp : fc){
            if (kvp.second != fa[kvp.first]){
                for (int i = 0; i < kvp.second; i++) b *= kvp.first;
            }
        }
        cout << b << endl;
    }
	return 0;
}

