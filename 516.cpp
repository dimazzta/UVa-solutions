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
vector<int> spf(nax);
vi primes;

void sieve(){
    for (int i = 2; i < nax; i++) spf[i] = i;
    for (int i = 2; i < nax; i++){
        if (spf[i] == i){
            for (ll j = (ll)i * i; j < nax; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
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
    string s;
    while(getline(cin, s)){
        if (s == "0") break;
        stringstream ss(s);
        int p, e;
        int prime = 1;
        while(ss >> p >> e){
            for (int i = 0; i < e; i++) prime *= p;
        }
        prime--;

        map<int, int> f = factorize(prime);

        bool r = false;
        for (auto it = f.rbegin(); it != f.rend(); it++){
            if (r) cout << " ";
            r = true;
            cout << it->first << " " << it->second;
        }
        cout << endl;
    }
	return 0;
}

