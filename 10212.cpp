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

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll n, m;
    while(cin >> n >> m){
        ll last = 1;
        for (ll i = n; i >= n - m + 1; i--){
            last *= i;
            while(last % 10 == 0) last /= 10;
            last %= 1000000000;
        }
        cout << last % 10 << endl;
    }

	return 0;
}

