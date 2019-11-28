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

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll n;
    while(cin >> n, n){
        if (ceil(sqrt(n)) * ceil(sqrt(n)) == n){
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
	return 0;
}

