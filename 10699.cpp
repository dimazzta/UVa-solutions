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

const int nax = 1e6 + 5;
vi ndif(nax);

void sieve(){
    for (int i = 2; i < nax; i++){
        if (!ndif[i]){
            for (int j = i; j < nax; j += i){
                ndif[j]++;
            }
        }
    }
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
        cout << n << " : " << ndif[n] << endl;
    }
	return 0;
}

